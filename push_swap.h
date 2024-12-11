/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:34:40 by mzolotar          #+#    #+#             */
/*   Updated: 2024/12/11 21:20:00 by mzolotar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──includes:──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

# include "libft/libft.h"
# include <limits.h>  //limits
# include <stdbool.h> //bollean
# include <stddef.h>  // size_t
# include <stdio.h>   //printf
# include <stdlib.h>  //exit

//#➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌───struct:──╌╌➣⋆➣╌─╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔#

typedef struct s_stack_node
{
	int value;                        // list -ok
	int index;                        // list -ok
	int push_cost;                    // list -ok
	bool above_median;                // list -ok
	bool cheapest;                    // list -ok
	struct s_stack_node *target_node; // list -ok
	struct s_stack_node *next;        // list - ok
	struct s_stack_node *prev;        // list - ok
}				t_stack_node;

/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Main:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/
// push_swap.c (2/5)
void			push_swap(t_stack_node **a, t_stack_node **b);
// int main (int argc, char **argv);

/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Errors:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/
// error_utils.c (5/5)
void			error_exit(t_stack_node **list, char **argv, bool argc_flag_2);
void			free_split_argv(char **argv);
int				error_syntax_argv(char *argv_nbr);
int				error_repetition_int(t_stack_node *list, int number);
void			free_stack_list(t_stack_node **list);

/*#◉──▢◇▢───◉•◉───▣───▢init and add: list_nodes.▢───▣───◉•◉────▢◇▢──◉#*/
// init_list_utils.c (3/5)
// static void	initialize_node(t_stack_node *node, int number);
void			add_node(t_stack_node **list, int number);
void	check_and_init_list(t_stack_node **a, char **argv, bool argc_flag_2);
		

/*#◉────▢◇▢───▣───◉•◉───▣───▢stack utils:▢───▣───◉•◉───▣───▢◇▢────◉#*/
// stack_utils.c (4/5)
t_stack_node	*find_last_node(t_stack_node *list);
t_stack_node	*find_smalles_value_list(t_stack_node *list);
t_stack_node	*find_biggest_value_list(t_stack_node *list);
int				list_size(t_stack_node *list);


/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Algotihtms:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/
// push_swap_utils.c (5/5)
void	rotate_both(t_stack_node **a, t_stack_node **b,t_stack_node *cheapest_node);
void	rev_rotate_both(t_stack_node **a, t_stack_node **b,t_stack_node *cheapest_node);
void	move_b_to_a(t_stack_node **a, t_stack_node **b);
void	move_a_to_b(t_stack_node **a, t_stack_node **b);
void	min_on_top(t_stack_node **a);


// algorithm_utils.c (5/5)
int	check_stack_is_ordened(t_stack_node **list); //(0 false, 1 frue)
void			order_three(t_stack_node **list);
void			current_index(t_stack_node *list);
void			prep_for_push(t_stack_node **list, t_stack_node *top_node,
					char stack_name);
t_stack_node	*get_cheapest(t_stack_node *list);

// init_a_to_b.c (4/5)
// static void set_target_a(t_stack_node *a, t_stack_node *b);
// static void	cost_analysis_a(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *list);
void			init_nodes_a_data(t_stack_node *a, t_stack_node *b);

// init_b_to_a.c (2/5)
// static void	set_target_b(t_stack_node *a, t_stack_node *b);
void			init_nodes_b_data(t_stack_node *a, t_stack_node *b);

/*#◉───▣───▢◇▢───▣───◉•◉───▣───▢Commands:▢───▣───◉•◉───▣───▢◇▢───▣───◉#*/
// swap_command.c (4/5)
// static void swap (t_stack_node **list);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// push_command.c (3/5)
// static void push (t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

// rotate_command.c (4/5)
// static void	rotate(t_stack_node **list);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// reverse_rotate_comand.c (4/5)
// static void	reverse_rotate(t_stack_node **list);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif