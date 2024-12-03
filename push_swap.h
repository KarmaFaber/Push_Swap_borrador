/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:34:40 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/03 09:59:47 by mzolotar         ###   ########.fr       */
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

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌───struct:──╌╌➣⋆➣╌─╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

typedef struct s_stack_node
{
	int value;                               //list -ok
    int	current_position;                    //list
    
    
    //struct t_stack_node *position;                 //para testeo- imprimir la lista enlazada- print_list
    struct s_stack_node *target_node;        //list
    struct s_stack_node *next;               //list - ok
    struct s_stack_node *prev;               //list - ok
    
}	t_stack_node;


//#➵⤐───╌╌➣⋆➣╌─╌──⤏➵•➵⤐───╌╌➣⋆➣╌╌──text:──╌╌➣⋆➣╌╌───⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

// main.c (1/5)
// int main (int argc, char **argv);

//stack_utils.c (5/5)
t_stack_node *find_last_node(t_stack_node *head);
void add_node(t_stack_node **list, int number);
void check_and_init_list(t_stack_node **a, char **argv, bool argc_flag_2); //crear lista + nodos
int list_size (t_stack_node *list);
t_stack_node *find_smales_value_list (t_stack_node *list);


// error_utils.c (5/5)
void	error_exit(t_stack_node **a, char **argv, bool argc_flag_2);
void	free_split_argv(char **argv);
int error_syntax_argv (char *argv_nbr);
int error_repetition_int (t_stack_node *a, int number);
void	free_stack_list(t_stack_node **stack);


//swap_comand.c (/5)
//swap
//sa
//sb
//ss

//push_comand.c (/5)
//pa
//pb

//rotate_comand.c (/5)
//ra
//rb
//rr

//reverse_rotate_comand.c (/5)
//rra
//rrb
//rrr



#endif