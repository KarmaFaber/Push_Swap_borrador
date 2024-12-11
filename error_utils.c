/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:14:24 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/11 20:46:38 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

void	error_exit(t_stack_node **list, char **argv, bool argc_flag_2)
{
	free_stack_list(list);
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

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

/**
 * @brief
 *
 * @param
 * @return
 */

int	error_syntax_argv(char *argv_nbr)
{
	if (!(*argv_nbr == '+' || *argv_nbr == '-' || (*argv_nbr >= '0'
				&& *argv_nbr <= '9')))
		return (1);
	if ((*argv_nbr == '+' || *argv_nbr == '-') && !(argv_nbr[1] >= '0'
			&& argv_nbr[1] <= '9'))
		return (1);
	while (*++argv_nbr)
	{
		if (!(*argv_nbr >= '0' && *argv_nbr <= '9'))
			return (1);
	}
	return (0);
}

/**
 * @brief
 *
 * @param
 * @return
 */

int	error_repetition_int(t_stack_node *list, int number)
{
	if (list == NULL)
		return (0);
	while (list)
	{
		if (list->value == number)
			return (1);
		list = list->next;
	}
	return (0);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	free_stack_list(t_stack_node **list)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (list == NULL)
		return ;
	current = *list;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*list = NULL;
}
