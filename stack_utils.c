/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:30:39 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/02 20:24:41 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 *
 * @param
 * @return
 */

//append_node


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
    while(argv[i])
    {
        
        //if(error_syntax_argv(argv[i]))
            //error_exit(a, argv, argc_flag_2);
        number= ft_atol(argv[i]);
        if (number > INT_MAX || number < INT_MIN)
            error_exit(a, argv, argc_flag_2);
        //if (error_repetition_int(*a, (int)nbr))
		//	error_exit(a, argv, argc_flag_2);
        
        //append_node(a, (int)number);
        //++i;

        
    }
    if(argc_flag_2)
        free_split_argv(argv);
}


