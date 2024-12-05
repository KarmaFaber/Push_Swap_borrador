/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:20:06 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/05 08:14:24 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

static void	swap(t_stack_node **head)
{
	int	size;

	size = list_size(*head);
	if (*head == NULL || head == NULL || size == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	sa(t_stack_node **a)
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

void	sb(t_stack_node **b)
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

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
