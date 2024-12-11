/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:13:01 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/11 10:13:49 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

int check_stack_is_ordened(t_stack_node **list)
{
	t_stack_node	*current;

	if (list == NULL || *list == NULL)
	{
		//ft_printf("\033[0;32m✅ SUCCESS: la lista está vacía o no existe (head == NULL o *head == NULL)\n\033[0m");
		return (1);
	}
	current = *list;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
		{
			//ft_printf("\033[1;31m🛑 ERROR: la lista está desordenada, hay que hacer cosas de unicornios locos (mensaje de checker)\n\033[0m");
			return (0);
		}
		current = current->next;
	}
	//ft_printf("\033[0;32m✅ SUCCESS: la lista está ordenada\n\033[0m");
	return (1); // Si no se encontró desorden, está ordenada.
}

/**
 * @brief
 *
 * @param
 * @return
 */

void order_three(t_stack_node **list)
{
    if (!list || !*list) 
        return;

    if ((list_size(*list) != 3) || (check_stack_is_ordened(list)))
        return;

    if (find_biggest_value_list(*list) == *list)
        ra(list);
    else if((*list)->next == find_biggest_value_list(*list)) 
        rra(list);
    if ((*list)->value > (*list)->next->value)
        sa(list);
        
}
