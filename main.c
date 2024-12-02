/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:34:44 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/02 11:59:19 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */









/*
char *allocate_stack(int *dest, int *src, size_t size)
{



}






//check argv errors:

int validate_argv(t_stack *stack_a)
{
	
	//argv_is_int
		//free_and_exit_with_errors
	//argv_is_int_max
		//free_and_exit_with_errors
	//argv_is_duplicated
		//free_and_exit_with_errors
}

int argv_is_int(t_stack *stack_a)
{


}


int argv_is_int_max (t_stack *stack_a)
{


}


int argv_is_duplicated(t_stack *stack_a)
{


}
*/

int	main(int argc, char *argv[])
{
	t_stack a;
	t_stack b;
	size_t size;

	a.stack_a = NULL;
	b.stack_b = NULL;
	
	size = malloc_size (argv[1]);

	ft_printf("%i\n", size);
	
	ft_printf("%c\n", argv[1][1]);
	ft_printf("%c\n", argv[1][2]);
	ft_printf("%c\n", argv[1][3]);
	
	
	if (argc < 2)
		exit(0);
	
	
	//malloc and alocate stack_a + ft_atoi
	malloc_and_aloccate_stack(&a, argv[1], size);


	//ft_printf("%i\n", a.stack_a[0]);
	//ft_printf("%i\n", a.stack_a[1]);
	//ft_printf("%i\n", a.stack_a[2]);
	
	//validate_argv
	
	//malloc and alocate stack_b
	

	//// Liberar memoria al final del programa
	free_stacks(&a, &b);
	
	return (0);
}
