/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:30:39 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/11 20:55:34 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

t_stack_node	*find_last_node(t_stack_node *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/**
 * @brief
 *
 * @param
 * @return
 */

t_stack_node	*find_smalles_value_list(t_stack_node *list)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (list == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (list)
	{
		if (list->value < smallest)
		{
			smallest = list->value;
			smallest_node = list;
		}
		list = list->next;
	}
	return (smallest_node);
}

/**
 * @brief
 *
 * @param
 * @return
 */

t_stack_node	*find_biggest_value_list(t_stack_node *list)
{
	long			biggest;
	t_stack_node	*biggest_node;

	if (list == NULL)
		return (NULL);
	biggest = LONG_MIN;
	while (list)
	{
		if (list->value > biggest)
		{
			biggest = list->value;
			biggest_node = list;
		}
		list = list->next;
	}
	return (biggest_node);
}

/**
 * @brief
 *
 * @param
 * @return
 */

int	list_size(t_stack_node *list)
{
	int	count;

	if (list == NULL)
		return (0);
	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}
