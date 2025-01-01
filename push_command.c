/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:22:10 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/01 12:18:52 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 *
 * 🚨 attention If stack empty (i.e. NULL)
 * @param
 * @return
 */

static void	push(t_stack_list **dest, t_stack_list **src)
{
	t_stack_list	*node_to_push;

	if (!src || !*src)
	{
		return ;
	}
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	pa(t_stack_list **a, t_stack_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	pb(t_stack_list **b, t_stack_list **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
