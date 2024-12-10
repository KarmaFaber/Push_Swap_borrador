/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:34:40 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/10 11:07:09 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──includes:──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

# include "libft/libft.h"
# include <stdio.h>  //printf
# include <stdlib.h> //exit
#include <stddef.h> // size_t
# include <stdbool.h> //bollean
#include <limits.h> //limits

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌───struct:──╌╌➣⋆➣╌─╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

typedef struct s_stack_node
{
	int value;                               //list -ok
    int	current_position;                    //list
    int index;                               //list
    
    

    struct s_stack_node *target_node;        //list
    struct s_stack_node *next;               //list - ok
    struct s_stack_node *prev;               //list - ok
    
}	t_stack_node;


//#➵⤐───╌╌➣⋆➣╌─╌──⤏➵•➵⤐───╌╌➣⋆➣╌╌──text:──╌╌➣⋆➣╌╌───⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

// main.c (1/5)
// int main (int argc, char **argv);


// init_list_utils.c (2/5)
void add_node(t_stack_node **list, int number);
void check_and_init_list(t_stack_node **a, char **argv, bool argc_flag_2); //crear lista + nodos


//stack_utils.c (5/5)
t_stack_node *find_last_node(t_stack_node *list);
int list_size (t_stack_node *list);
t_stack_node *find_smalles_value_list (t_stack_node *list);
t_stack_node *find_biggest_value_list(t_stack_node *list);
void order_tree(t_stack_node **list);


// error_utils.c (5/5)
void	error_exit(t_stack_node **list, char **argv, bool argc_flag_2);
void	free_split_argv(char **argv);
int error_syntax_argv (char *argv_nbr);
int error_repetition_int (t_stack_node *list, int number);
void	free_stack_list(t_stack_node **list);


//swap_command.c (4/5)
//static void swap (t_stack_node **list);
void sa(t_stack_node **a);
void sb(t_stack_node **b);
void ss(t_stack_node **a, t_stack_node **b);


//push_command.c (3/5)
//static void push (t_stack_node **dest, t_stack_node **src);
void pa(t_stack_node **a, t_stack_node **b);
void pb (t_stack_node **b, t_stack_node **a);


//rotate_command.c (4/5)
//static void	rotate(t_stack_node **list);
void ra (t_stack_node **a);
void rb (t_stack_node **b);
void rr (t_stack_node **a, t_stack_node **b);


//reverse_rotate_comand.c (4/5)
//static void	reverse_rotate(t_stack_node **list);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

//push_swap_utils.c (/5)
int check_stack_is_ordened(t_stack_node **list); //(0 false, 1 frue)
void	push_swap(t_stack_node **a, t_stack_node **b);





#endif