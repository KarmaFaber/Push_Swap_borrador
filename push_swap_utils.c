/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:48 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/09 13:03:04 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

int check_stack_is_ordened(t_stack_node **head)
{
	t_stack_node	*current;

	if (head == NULL || *head == NULL)
	{
		//ft_printf("\033[0;32m✅ SUCCESS: la lista está vacía o no existe (head == NULL o *head == NULL)\n\033[0m");
		return (1);
	}
	current = *head;
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

void	push_swap(t_stack_node **a, t_stack_node **b)
{
    
    if (!a || !*a || !b)
    {
        ft_printf("\033[1;31m🛑 ERROR: pilla NULL en push_swap \n\033[0m");
        return ;
    }
    
    
    if ((!check_stack_is_ordened(a)) && (list_size(*a) == 3))
        order_tree(a);
    else
    {
        while (list_size(*a) > 3)
            pb (b, a); 
		if (list_size(*a) == 3)
        	order_tree(a);
    }
	
	//ordenar b 
	
	
        
}
