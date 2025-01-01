/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:33:02 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/01 12:18:30 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */
static void	set_target_b(t_stack_list *a, t_stack_list *b)
{
	t_stack_list	*current_a;
	t_stack_list	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->value > b->value)
				&& (current_a->value < best_match_index))
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smalles_value_list(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	init_nodes_b_data(t_stack_list *a, t_stack_list *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
