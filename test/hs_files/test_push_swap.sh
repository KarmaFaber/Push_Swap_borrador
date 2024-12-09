#!/bin/bash

# Colores para mensajes
RED="\033[0;31m"
GREEN="\033[0;32m"
CYAN="\033[0;36m"
RESET="\033[0m"

# Ruta al ejecutable
EXEC="./push_swap"

# Preguntar por el número de números aleatorios
echo -e "${CYAN}¿Cuántos números aleatorios deseas generar para la prueba?${RESET}"
read -p "> " r_numbers

# Validar entrada
if ! [[ "$r_numbers" =~ ^[0-9]+$ ]]; then
    echo -e "${RED}Error: Por favor, introduce un número válido.${RESET}"
    exit 1
fi

# Generar números aleatorios únicos entre INT_MIN e INT_MAX
random_numbers=$(python3 -c "
import random
random.seed()
print(' '.join(map(str, random.sample(range(-2147483648, 2147483647), $r_numbers))))
")

# Guardar los números generados para referencia
mkdir -p test
numbers_file="test/test_outputs/generated_numbers.log"
echo "$random_numbers" > "$numbers_file"
#code test/test_outputs/generated_numbers.log

echo -e "${CYAN}Ejecutando valgrind con los siguientes números:${RESET}"
echo "$random_numbers"



# Crear un archivo para registrar la salida del programa
output_file="test/test_outputs/command_output.log"

# Crear un archivo para registrar la salida de Valgrind
valgrind_log="test/valgrind_outputs/valgrind_output_$(date +%Y%m%d_%H%M%S).log"

# Ejecutar Valgrind con el programa y redirigir ambas salidas
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no --log-file="$valgrind_log" -s $EXEC $random_numbers > "$output_file"

# Abrir ambos archivos para revisar las salidas (opcional)
code "$output_file"
code "$valgrind_log"

# Opcional: Ejecutar un script para mostrar automáticamente el log de Valgrind si es necesario
test/hs_files/./open_valgrind_log.sh



# Filtrar y contar únicamente los comandos válidos
commands=("sa" "sb" "ss" "ra" "rb" "rr" "pa" "pb" "rra" "rrb" "rrr")
n_commands=$(grep -Eo "$(IFS=\|; echo "${commands[*]}")" "$output_file" | wc -l)

# Registrar los movimientos (para calcular mínimo, máximo y promedio)
movement_counts=("$n_commands")

# Agregar estadísticas (mínimo, promedio, máximo)
min_moves=${movement_counts[0]}
max_moves=${movement_counts[0]}
total_moves=0

for moves in "${movement_counts[@]}"; do
    total_moves=$((total_moves + moves))
    if ((moves < min_moves)); then
        min_moves=$moves
    fi
    if ((moves > max_moves)); then
        max_moves=$moves
    fi
done

average_moves=$((total_moves / ${#movement_counts[@]}))

# Crear el archivo de resumen
summary_file="test/test_outputs/summary.log"
{
    echo -e "Numbers   Lowest   Average   Highest"
    printf "%-10d %-8d %-9d %-7d\n" "$r_numbers" "$min_moves" "$average_moves" "$max_moves"
} > "$summary_file"
code test/test_outputs/summary.log

# Mostrar el resumen
echo -e "${GREEN}Prueba finalizada.${RESET}"
echo "Resumen:"
echo "  - r_numbers: $r_numbers"
echo "  - n_commands: $n_commands"

