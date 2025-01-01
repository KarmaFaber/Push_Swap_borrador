/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:13:01 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/01 12:17:46 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

int	check_stack_is_ordened(t_stack_list **list)
{
	t_stack_list	*current;

	if (list == NULL || *list == NULL)
	{
		return (1);
	}
	current = *list;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	order_three(t_stack_list **list)
{
	if (!list || !*list)
		return ;
	if ((list_size(*list) != 3) || (check_stack_is_ordened(list)))
		return ;
	if (find_biggest_value_list(*list) == *list)
		ra(list);
	else if ((*list)->next == find_biggest_value_list(*list))
		rra(list);
	if ((*list)->value > (*list)->next->value)
		sa(list);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	current_index(t_stack_list *list)
{
	int	i;
	int	median;

	i = 0;
	if (list == NULL)
		return ;
	median = list_size(list) / 2;
	while (list)
	{
		list->index = i;
		if (i <= median)
			list->above_median = true;
		else
			list->above_median = false;
		list = list->next;
		i++;
	}
}
/**
 * @brief
 *
 * @param
 * @return
 */

void	prep_for_push(t_stack_list **list, t_stack_list *top_node,
		char stack_name)
{
	while (*list != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(list);
			else
				rra(list);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(list);
			else
				rrb(list);
		}
	}
}
/**
 * @brief
 *
 * @param
 * @return
 */

t_stack_list	*get_cheapest(t_stack_list *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->cheapest)
			return (list);
		list = list->next;
	}
	return (NULL);
}
