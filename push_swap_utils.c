/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:48 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/05 08:36:56 by mzolotar         ###   ########.fr       */
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
		ft_printf("\033[0;32m✅ SUCCESS: la lista está vacía o no existe (head == NULL o *head == NULL)\n\033[0m");
		return (1);
	}
	current = *head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
		{
			ft_printf("\033[1;31m🛑 ERROR: la lista está desordenada, hay que hacer cosas de unicornios locos (mensaje de checker)\n\033[0m");
			return (0);
		}
		current = current->next;
	}
	ft_printf("\033[0;32m✅ SUCCESS: la lista está ordenada\n\033[0m");
	return (1); // Si no se encontró desorden, está ordenada.
}

void	push_swap(t_stack_node **list)
{
	t_stack_node *current;
	
	if (*list == NULL || list == NULL)
		return ;
		
	current = *list; // Puntero temporal para iterar sin modificar `list`
	
	while (current->next != NULL)
    {
        if (current->value > current->next->value)
        {
            sa(list); // Realiza el swap en la lista original
            break;    // Sale del bucle para verificar el orden nuevamente
        }
        current = current->next;
    }

	if (check_stack_is_ordened(list))
		return ;
	else
		push_swap(list);
}