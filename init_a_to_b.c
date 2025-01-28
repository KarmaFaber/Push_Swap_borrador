/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:55:01 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/28 13:52:41 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

static void	set_target_a(t_stack_list *a, t_stack_list *b)
{
	t_stack_list	*current_b;
	t_stack_list	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if ((current_b->value < a->value)
				&& (current_b->value > best_match_index))
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_biggest_value_list(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

/**
 * @brief
 *
 * @param
 * @return
 */

static void	cost_analysis_a(t_stack_list *a, t_stack_list *b)
{
	int	size_a;
	int	size_b;

	size_a = list_size(a);
	size_b = list_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = size_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += size_b - (a->target_node->index);
		a = a->next;
	}
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	set_cheapest(t_stack_list *list)
{
	long			cheapest_value;
	t_stack_list	*cheapest_node;

	if (list == NULL)
		return ;
	cheapest_value = LONG_MAX;
	while (list)
	{
		if (list->push_cost < cheapest_value)
		{
			cheapest_value = list->push_cost;
			cheapest_node = list;
		}
		list = list->next;
	}
	cheapest_node->cheapest = true;
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	init_a_nodes_data(t_stack_list *a, t_stack_list *b)
{
	current_index_and_median(a);
	current_index_and_median(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
