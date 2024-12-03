/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:22:56 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/03 12:33:50 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

static void	reverse_rotate(t_stack_node **list)
{
	t_stack_node	*last;
	int				size;

	size = list_size(*list);
	if (*list == NULL ||list == NULL || size == 1)
		return ;
	last = find_last_node(*list);
	last->prev->next = NULL;
	last->next = *list;
	last->prev = NULL;
	*list = last;
	last->next->prev = last;
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
/**
 * @brief
 *
 * @param
 * @return
 */

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}