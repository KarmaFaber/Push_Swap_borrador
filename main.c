/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:34:44 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/11 13:38:39 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_stack_node *head)
{
    t_stack_node *position;
    
    position=head;
    while(position != NULL)
    {
        printf("%i -> ", position -> value); 
        position=position->next;
    }
    printf("NULL\n");  // Añadir para indicar el final de la lista
}

int	main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	
	a = NULL;
	b = NULL;
	//--------------------------1 - check argv-------------------------
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');


	//--------------------------2- init list and chaeck argv format -> error------------------------
	
	if (argc == 2)
		check_and_init_list(&a, argv, true);
	else
		check_and_init_list(&a, argv + 1, false);

	
	//--------------------------4- algorithm------------------------
	
	if(!check_stack_is_ordened(&a))
	{
		if(list_size(a)== 2)
			sa(&a);
		else if(list_size(a) == 3)
			order_three(&a);
		else
			push_swap(&a, &b);
	}
	
//ver listas testeo -----------------------------------------------------------------------------------
/*
	ft_printf("\033[0;35m\nlista a \033[0m\n");
	print_list(a);
	ft_printf("\033[0;35mfin de lista a \n\033[0m\n");

	ft_printf("\033[0;34mlista b \033[0m\n");
	print_list(b);
	ft_printf("\033[0;34mfin de lista b \033[0m\n");
*/
//ver listas fin testeo -----------------------------------------------------------------------------------

	//--------------------------5-free------------------------
	
	free_stack_list(&a);
	//free_stack_list(&b);			//quitar?? y liberar b en otro lado?
	return (0);
}
