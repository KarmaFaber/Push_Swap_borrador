/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:34:44 by mzolotar          #+#    #+#             */
/*   Updated: 2025/01/02 10:50:21 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// quitar esta f, solo es para testeo
void	print_list(t_stack_list *head)
{
	t_stack_list	*position;

	position = head;
	while (position != NULL)
	{
		printf("%i -> ", position->value);
		position = position->next;
	}
	printf("NULL\n");
}

/**
 * @brief
 *
 * @param
 * @return
 */

void	push_swap(t_stack_list **a, t_stack_list **b)
{
	int	a_size;

	a_size = list_size(*a);
	if (a == NULL || *a == NULL || b == NULL)
		return ;
	if ((!check_stack_is_ordened(*a)) && (a_size-- > 3))
		pb(b, a);
	if ((!check_stack_is_ordened(*a)) && (a_size-- > 3))
		pb(b, a);
	while ((!check_stack_is_ordened(*a)) && (a_size-- > 3))
	{
		init_nodes_a_data(*a, *b);
		move_a_to_b(a, b);
	}
	order_three(a);
	while (*b)
	{
		init_nodes_b_data(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

int	main(int argc, char **argv)
{
	t_stack_list	*a;
	t_stack_list	*b;

	a = NULL;
	b = NULL;
	//--------------------------1 - check argv-------------------------
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		exit(EXIT_SUCCESS);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	//--------------------------2- init list and chaeck argv format-> error------------------------
	if (argc == 2)
		check_and_init_list(&a, argv, true);
	else
		check_and_init_list(&a, argv + 1, false);

		
	//--------------------------4- algorithm------------------------
	if (!check_stack_is_ordened(a))
	{
		if (list_size(a) == 2)
			sa(&a);
		else if (list_size(a) == 3)
			order_three(&a);
		else
			push_swap(&a, &b);
	}
	// ver listas testeo -----------------------------------------------------------------------------------
	/*
		ft_printf("\033[0;35m\nlista a \033[0m\n");
		print_list(a);
		ft_printf("\033[0;35mfin de lista a \n\033[0m\n");
		ft_printf("\033[0;34mlista b \033[0m\n");
		print_list(b);
		ft_printf("\033[0;34mfin de lista b \033[0m\n");
	*/
	// ver listas fin testeo -----------------------------------------------------------------------------------
	//--------------------------5-free------------------------
	free_stack_list(&a);
	// free_stack_list(&b);			//quitar?? y liberar b en otro lado?
	return (0);
}
