/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:14:24 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/02 20:14:30 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

void	error_exit(t_stack_node **a, char **argv, bool argc_flag_2)
{
	free_stack_list(a);
	if (argc_flag_2)
		free_split_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
	
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	free_split_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}


/**
 * @brief
 *
 * @param
 * @return
 */
//error_syntax_argv




/**
 * @brief
 *
 * @param
 * @return
 */

//error_repetition_int


/**
 * @brief
 *
 * @param
 * @return
 */

void	free_stack_list(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}


