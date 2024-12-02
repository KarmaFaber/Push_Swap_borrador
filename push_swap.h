/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:34:40 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/02 11:28:29 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──includes:──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

# include "libft/libft.h"
# include <stdio.h>  //printf
# include <stdlib.h> //exit
#include <stddef.h> // size_t

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌───struct:──╌╌➣⋆➣╌─╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

typedef struct s_stack
{
	int	*stack_a;
    int	*stack_b;
}	t_stack;


//#➵⤐───╌╌➣⋆➣╌─╌──⤏➵•➵⤐───╌╌➣⋆➣╌╌──text:──╌╌➣⋆➣╌╌───⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

// main.c
// int main (int argc, char **argv);

//utils.c
size_t malloc_size(char *argv);
void malloc_and_aloccate_stack(t_stack *stack, char *argv, size_t malloc_size);


// free.c
void free_and_exit_without_errors(t_stack *stack);
void free_and_exit_with_errors(t_stack *stack);
void free_stacks(t_stack *stack_a, t_stack *stack_b);

#endif