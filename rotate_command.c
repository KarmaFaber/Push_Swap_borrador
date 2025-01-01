/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:22:29 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/01 12:19:36 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

static void	rotate(t_stack_list **list)
{
	t_stack_list	*last_node;
	int				size;

	size = list_size(*list);
	if (list == NULL || *list == NULL || size == 1)
		return ;
	last_node = find_last_node(*list);
	last_node->next = *list;
	*list = (*list)->next;
	(*list)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	ra(t_stack_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	rb(t_stack_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	rr(t_stack_list **a, t_stack_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
