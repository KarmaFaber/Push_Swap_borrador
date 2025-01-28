/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:48 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/28 13:34:00 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

void	rotate_both(t_stack_list **a, t_stack_list **b,
		t_stack_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index_and_median(*a);
	current_index_and_median(*b);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	rev_rotate_both(t_stack_list **a, t_stack_list **b,
		t_stack_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index_and_median(*a);
	current_index_and_median(*b);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	move_a_to_b(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if ((cheapest_node->above_median)
		&& (cheapest_node->target_node->above_median))
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	move_b_to_a(t_stack_list **a, t_stack_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}
/**
 * @brief
 *
 * @param
 * @return
 */

void	min_on_top(t_stack_list **a)
{
	while ((*a)->value != find_smalles_value_list(*a)->value)
	{
		if (find_smalles_value_list(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
