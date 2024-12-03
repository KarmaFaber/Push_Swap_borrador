/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:34:44 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/03 12:36:43 by mzolotar         ###   ########.fr       */
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

//--------------------------- 1- test argv-----------------------------------------------------

	ft_printf("---------split--------\n");
	int i=0;
	while(argv[i] != NULL)
	{
		ft_printf("%s\n", argv[i]);
		i++;
	}
	ft_printf("---------fin de split--------\n\n");

//--------------------------- 1- fin test argv-----------------------------------------------------

	//--------------------------2- init list and chaeck argv format -> error------------------------
	
	if (argc == 2)
		check_and_init_list(&a, argv, true);
	else
		check_and_init_list(&a, argv + 1, false);

//--------------------------2 -test- init list and chaeck argv format----------------------------------------------------

	ft_printf("---------lista a--------\n");
	print_list(a);
	ft_printf("---------fin de lista a--------\n\n");
	
	ft_printf("---------lista a: buscar smallest--------\n");
	t_stack_node *smallest_node= find_smales_value_list(a);
	
	if (smallest_node != NULL)
        printf("El valor más pequeño es: %d\n", smallest_node->value);
    else
	{
        printf("La lista está vacía.\n");
	}
	ft_printf("---------fin lista a: buscar smallest--------\n\n");

//--------------------------2 -fin test- init list and chaeck argv format----------------------------------------------------	
	//--------------------------3- comands------------------------
	//...
//-------------------------3-test-comands----------------------------------------------------
	//sa(&a);
	//ft_printf("---------lista a--------\n");
	//print_list(a);
	//ft_printf("---------fin de lista a--------\n\n");

	pb (&b, &a);
	pb (&b, &a);
	ft_printf("---------lista a--------\n");
	print_list(a);
	ft_printf("---------fin de lista a--------\n\n");
	ft_printf("---------lista b--------\n");
	print_list(b);
	ft_printf("---------fin de lista b--------\n\n");
/*
	pa (&a, &b);
	ft_printf("---------lista a--------\n");
	print_list(a);
	ft_printf("---------fin de lista a--------\n\n");
	ft_printf("---------lista b--------\n");
	print_list(b);
	ft_printf("---------fin de lista b--------\n\n");
*/
	ra(&a);
	ft_printf("---------lista a--------\n");
	print_list(a);
	ft_printf("---------fin de lista a--------\n\n");

	rb(&b);
	ft_printf("---------lista b--------\n");
	print_list(b);
	ft_printf("---------fin de lista b--------\n\n");

	rr(&a, &b);
	ft_printf("---------lista a--------\n");
	print_list(a);
	ft_printf("---------fin de lista a--------\n\n");
	ft_printf("---------lista b--------\n");
	print_list(b);
	ft_printf("---------fin de lista b--------\n\n");



	rra(&a);
	ft_printf("---------lista a--------\n");
	print_list(a);
	ft_printf("---------fin de lista a--------\n\n");

	rrb(&b);
	ft_printf("---------lista b--------\n");
	print_list(b);
	ft_printf("---------fin de lista b--------\n\n");

	rrr(&a, &b);
	ft_printf("---------lista a--------\n");
	print_list(a);
	ft_printf("---------fin de lista a--------\n\n");
	ft_printf("---------lista b--------\n");
	print_list(b);
	ft_printf("---------fin de lista b--------\n\n");
	

//-------------------------3-fin test-comands----------------------------------------------------
	//--------------------------4- algorithm------------------------







//-------------------------4--test-algorithm----------------------------------------------------

	//--------------------------5-free------------------------
	
	free_stack_list(&a);
	free_stack_list(&b);			//quitar??
	return (0);
}
