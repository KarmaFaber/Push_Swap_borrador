#!/bin/bash

# Colores para mensajes
RED="\033[0;31m"
GREEN="\033[0;32m"
CYAN="\033[0;36m"
RESET="\033[0m"

# Ruta al ejecutable
EXEC="./push_swap"

# Crear carpetas si no existen
mkdir -p test/test_outputs/single_test test/test_outputs/multiple_tests_100 test/test_outputs/multiple_tests_500 test/valgrind_outputs test/hs_files

# Función para ejecutar un solo test
run_single_test() {
    local num_numbers=$1
    local output_dir="test/test_outputs/single_test"
    local summary_log="${output_dir}/summary.log"

    # Crear el directorio si no existe
    mkdir -p "$output_dir"
#!/bin/bash

# Colores para mensajes
RED="\033[0;31m"
GREEN="\033[0;32m"
CYAN="\033[0;36m"
RESET="\033[0m"

# Ruta al ejecutable
EXEC="./push_swap"

# Crear carpetas si no existen
mkdir -p test/hs_files test/test_outputs test/valgrind_outputs

# Función para ejecutar un solo test
run_single_test() {
    local num_numbers=$1
    local output_dir=$2

    random_numbers=$(python3 -c "
import random
random.seed()
print(' '.join(map(str, random.sample(range(-2147483648, 2147483647), $num_numbers))))
")

    # Guardar números generados
    echo "$random_numbers" > "${output_dir}/generated_numbers.log"

    # Ejecutar Valgrind
    valgrind_log="${output_dir}/valgrind_output.log"
    command_output_log="${output_dir}/command_output.log"

    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no \
        --log-file="$valgrind_log" -s $EXEC $random_numbers > "$command_output_log"

    # Contar los comandos válidos
    commands=("sa" "sb" "ss" "ra" "rb" "rr" "pa" "pb" "rra" "rrb" "rrr")
    n_commands=$(grep -Eo "$(IFS=\|; echo "${commands[*]}")" "$command_output_log" | wc -l)

    echo "$n_commands"
}

# Función para ejecutar múltiples pruebas consecutivas
run_multiple_tests() {
    local num_numbers=$1
    local repetitions=$2
    local output_dir=$3

    mkdir -p "$output_dir"
    summary_file="${output_dir}/summary.log"
    echo -e "Test\tNumbers\tCommands" > "$summary_file"

    total_moves=0
    min_moves=-1
    max_moves=-1

    for ((i = 1; i <= repetitions; i++)); do
        test_dir="${output_dir}/test_$i"
        mkdir -p "$test_dir"
        moves=$(run_single_test "$num_numbers" "$test_dir")

        echo -e "$i\t$num_numbers\t$moves" >> "$summary_file"
        total_moves=$((total_moves + moves))

        if ((min_moves == -1 || moves < min_moves)); then
            min_moves=$moves
        fi
        if ((moves > max_moves)); then
            max_moves=$moves
        fi
    done

    average_moves=$((total_moves / repetitions))

    # Añadir estadísticas al resumen
    echo -e "\n# Summary for ${num_numbers} numbers:" >> "$summary_file"
    echo -e "Test\tNumbers\tLowest\tMedia\tHighest" >> "$summary_file"
    echo -e "$repetitions\t$num_numbers\t$min_moves\t$average_moves\t$max_moves" >> "$summary_file"

    code "$summary_file"
}

# Menú principal
echo -e "${CYAN}Selecciona el tipo de test que deseas ejecutar:${RESET}"
echo -e "1. Test único: elige el número de números aleatorios."
echo -e "2. Test múltiple: 10 pruebas con 100 números aleatorios."
echo -e "3. Test múltiple: 10 pruebas con 500 números aleatorios."
read -p "> " test_choice

case $test_choice in
    1)
        echo -e "${CYAN}¿Cuántos números aleatorios deseas generar para la prueba?${RESET}"
        read -p "> " r_numbers
        if ! [[ "$r_numbers" =~ ^[0-9]+$ ]]; then
            echo -e "${RED}Error: Por favor, introduce un número válido.${RESET}"
            exit 1
        fi
        run_single_test "$r_numbers" "test/test_outputs/single_test"
        ;;
    2)
        run_multiple_tests 100 10 "test/test_outputs/multiple_tests_100"
        ;;
    3)
        run_multiple_tests 500 10 "test/test_outputs/multiple_tests_500"
        ;;
    *)
        echo -e "${RED}Error: Selección inválida.${RESET}"
        exit 1
        ;;
esac

echo -e "${GREEN}Pruebas completadas.${RESET}"

    random_numbers=$(python3 -c "
import random
random.seed()
print(' '.join(map(str, random.sample(range(-2147483648, 2147483647), $num_numbers))))
")

    # Guardar números generados
    echo "$random_numbers" > "${output_dir}/generated_numbers.log"

    # Ejecutar Valgrind
    valgrind_log="${output_dir}/valgrind_output.log"
    command_output_log="${output_dir}/command_output.log"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no --log-file="$valgrind_log" -s $EXEC $random_numbers > "$command_output_log"

    

    # Contar los comandos válidos
    commands=("sa" "sb" "ss" "ra" "rb" "rr" "pa" "pb" "rra" "rrb" "rrr")
    n_commands=$(grep -Eo "$(IFS=\|; echo "${commands[*]}")" "$command_output_log" | wc -l)

    # Escribir resultados en el archivo summary.log
    echo -e "Test\tNumbers\tCommands" > "$summary_log"
    echo -e "1\t$num_numbers\t$n_commands" >> "$summary_log"

     # Mostrar estadísticas en el terminal
    echo -e "${CYAN}Estadísticas del test único:${RESET}"
    echo -e "Números generados: $num_numbers"
    echo -e "Total de comandos ejecutados: $n_commands"

    # Abrir el summary.log
    code "$summary_log"
}

# Función para ejecutar múltiples pruebas consecutivas
run_multiple_tests() {
    local num_numbers=$1
    local repetitions=$2
    local output_dir=$3

    mkdir -p "$output_dir"
    summary_file="${output_dir}/summary.log"
    echo -e "Test\tNumbers\tCommands" > "$summary_file"

    total_moves=0
    min_moves=-1
    max_moves=-1

    for ((i = 1; i <= repetitions; i++)); do
        test_dir="${output_dir}/test_$i"
        mkdir -p "$test_dir"
        moves=$(run_single_test "$num_numbers" "$test_dir")

        echo -e "$i\t$num_numbers\t$moves" >> "$summary_file"
        total_moves=$((total_moves + moves))

        if ((min_moves == -1 || moves < min_moves)); then
            min_moves=$moves
        fi
        if ((moves > max_moves)); then
            max_moves=$moves
        fi
    done

    average_moves=$((total_moves / repetitions))

    # Añadir estadísticas al resumen
    echo -e "\n# Summary for ${num_numbers} numbers:" >> "$summary_file"
    echo -e "Test\tNumbers\tLowest\tMedia\tHighest" >> "$summary_file"
    echo -e "$repetitions\t$num_numbers\t$min_moves\t$average_moves\t$max_moves" >> "$summary_file"

    code "$summary_file"
}

# Menú principal
echo -e "${CYAN}Selecciona el tipo de test que deseas ejecutar:${RESET}"
echo -e "1. Test único: elige el número de números aleatorios."
echo -e "2. Test múltiple: 10 pruebas con 100 números aleatorios."
echo -e "3. Test múltiple: 10 pruebas con 500 números aleatorios."
read -p "> " test_choice

case $test_choice in
    1)
        echo -e "${CYAN}¿Cuántos números aleatorios deseas generar para la prueba?${RESET}"
        read -p "> " r_numbers
        if ! [[ "$r_numbers" =~ ^[0-9]+$ ]]; then
            echo -e "${RED}Error: Por favor, introduce un número válido.${RESET}"
            exit 1
        fi
        run_single_test "$r_numbers" "test/test_outputs/single_test"
        ;;
    2)
        run_multiple_tests 100 10 "test/test_outputs/multiple_tests_100"
        ;;
    3)
        run_multiple_tests 500 10 "test/test_outputs/multiple_tests_500"
        ;;
    *)
        echo -e "${RED}Error: Selección inválida.${RESET}"
        exit 1
        ;;
esac

echo -e "${GREEN}Pruebas completadas.${RESET}"
