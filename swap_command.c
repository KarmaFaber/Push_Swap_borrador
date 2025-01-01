/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:20:06 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/01 12:19:57 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

static void	swap(t_stack_list **list)
{
	int	size;

	size = list_size(*list);
	if (*list == NULL || list == NULL || size == 1)
		return ;
	*list = (*list)->next;
	(*list)->prev->prev = *list;
	(*list)->prev->next = (*list)->next;
	if ((*list)->next)
		(*list)->next->prev = (*list)->prev;
	(*list)->next = (*list)->prev;
	(*list)->prev = NULL;
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	sa(t_stack_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}
/**
 * @brief
 *
 * @param
 * @return
 */

void	sb(t_stack_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	ss(t_stack_list **a, t_stack_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
