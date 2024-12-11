/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:48 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/11 10:40:53 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		//init_nodes_a
		//move_a_to_b
	}
	order_three(a);
	while(*b)
	{
		//init_nodes_b
		//move_b_to_a
	}
	//current_index
	//min_on_top
}
