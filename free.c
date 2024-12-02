/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:14:24 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/02 11:26:50 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

void free_and_exit_without_errors(t_stack *stack)
{
    // Liberar memoria asignada a stack_a y stack_b
    if (stack->stack_a)
        free(stack->stack_a);
    if (stack->stack_b)
        free(stack->stack_b);

    // Salir sin errores
    exit(0);
}


/**
 * @brief
 *
 * @param
 * @return
 */

void free_and_exit_with_errors(t_stack *stack)
{
    // Liberar memoria asignada a stack_a y stack_b
    if (stack->stack_a)
        free(stack->stack_a);
    if (stack->stack_b)
        free(stack->stack_b);

    // Imprimir error y salir con código de error
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
}



/**
 * @brief
 *
 * @param
 * @return
 */

void free_stacks(t_stack *stack_a, t_stack *stack_b)
{
    // Liberar memoria para stack_a
    if (stack_a->stack_a)
        free(stack_a->stack_a);
    
    // Liberar memoria para stack_b
    if (stack_b->stack_b)
        free(stack_b->stack_b);

    // Salir sin errores
    exit(0);
}

