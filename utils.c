/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:30:39 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/02 11:21:14 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

size_t malloc_size(char *argv)
{
	size_t spaces; 
	size_t total_len;

	spaces = ft_strchar_count(argv ,' ');
	total_len = spaces + 1;

	return (total_len);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void malloc_and_aloccate_stack(t_stack *stack, char *argv, size_t malloc_size)
{
	int i;
	int j;
	
	i=0;
	j=0;
	stack->stack_a = (int *) malloc (malloc_size * sizeof (int));
	if (!stack->stack_a)
	{
		ft_printf("Error allocating memory for stack.\n");
		exit(EXIT_FAILURE);
	}
	while (argv[i])
	{
		while (argv[i] == ' ')
			i++;
		if (argv[i])
		{
			stack->stack_a[j] = ft_atoi(&argv[i]);
			j++;
			while (argv[i] && argv[i] != ' ')
                i++;
		}
	}
	
}
/**
 * @brief
 *
 * @param
 * @return
 */




