/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:30:39 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/03 10:53:28 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/**
 * @brief
 *
 * @param
 * @return
 */

t_stack_node *find_last_node(t_stack_node *head)
{
    if(head == NULL)
        return (NULL);
    while(head-> next)
        head = head->next;
    return (head);
    
}

/**
 * @brief
 *
 * @param
 * @return
 */

void add_node(t_stack_node **list, int number)
{
    t_stack_node *node;
    t_stack_node *last_node;

    if (list == NULL)
        return;
    node = malloc(sizeof(t_stack_node));
    if (node == NULL)
        return;
    node->next =NULL;
    node->value = number;
    if (*list == NULL)
    {
        *list = node;
        node->prev =NULL;
    }
    else
    {
        last_node = find_last_node(*list);
        last_node->next =node;
        node->prev = last_node;
    }
}


/**
 * @brief
 *
 * @param
 * @return
 * 
 * 🏁 Flag is useful cause if true, i have the argv in the HEAP to free 
 * ya que lista ya fue creada y no necesitamos esos datos
 * 
 */

void check_and_init_list(t_stack_node **a, char **argv, bool argc_flag_2)
{
    long number;
    int i;

    i=0;
    //printf("entrando en check_and_init_list\n");
    while(argv[i])
    {
        
        if(error_syntax_argv(argv[i]))
            error_exit(a, argv, argc_flag_2);
            
        number= ft_atol(argv[i]);

        if (number > INT_MAX || number < INT_MIN)
            error_exit(a, argv, argc_flag_2);
            
        if (error_repetition_int(*a, (int)number))
			error_exit(a, argv, argc_flag_2);
        
        add_node(a, (int)number);
        ++i;
    }
    if(argc_flag_2)
        free_split_argv(argv);
    //printf("saliendo de check_and_init_list\n");
}

/**
 * @brief
 *
 * @param
 * @return
 */

int list_size (t_stack_node *list)
{
    int count;
    
    if (list == NULL)
        return (0);
    count = 0;  
    while(list)
    {
        list = list->next;
        count++;
    }
    return(count);
}


/**
 * @brief
 *
 * @param
 * @return
 */

t_stack_node *find_smales_value_list(t_stack_node *list)
{
    long smallest;
    t_stack_node *smallest_node;
    
    if (list == NULL)  
        return(NULL);
    smallest =LONG_MAX;
        
    while(list)
    {
        if(list->value < smallest)
        {
            smallest = list->value;
            smallest_node=list;
        }
        list=list->next;  
    }

    return(smallest_node);
}


