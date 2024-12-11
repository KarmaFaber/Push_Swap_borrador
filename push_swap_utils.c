/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:48 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/11 13:22:06 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node) 
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

/**
 * @brief
 *
 * @param
 * @return
 */

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node) 
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) 
		rrr(a, b); 
	current_index(*a); 
	current_index(*b);
}

/**
 * @brief
 *
 * @param
 * @return
 */

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if ((cheapest_node->above_median) && (cheapest_node->target_node->above_median))
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median)) 
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

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
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

static void	min_on_top(t_stack_node **a) 
{
	while ((*a)->value != find_smalles_value_list(*a)->value) 
	{
		if (find_smalles_value_list(*a)->above_median) 
			ra(a);
		else
			rra(a);
	}
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int a_size;
	
	a_size = list_size(*a);
    if (a == NULL || *a == NULL || b == NULL)
		return;
    if ((!check_stack_is_ordened(a)) && (a_size-- > 3))
		pb(b, a);
	if ((!check_stack_is_ordened(a)) && (a_size-- > 3))
		pb(b, a);
	while((!check_stack_is_ordened(a)) && (a_size-- > 3))
	{
		init_nodes_a_data(*a, *b);
		move_a_to_b(a, b);
	}
	order_three(a);
	while(*b)
	{
		init_nodes_b_data(*a,*b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
