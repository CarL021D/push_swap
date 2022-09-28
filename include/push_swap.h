/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:51:52 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/29 00:20:17 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define SUCCESS 1
# define ERROR 0
# define STACK_A 1
# define STACK_B 2

typedef struct s_stack
{
	int		value;
	int		index;
	int		current_pos;
	int		cost_a;
	int		cost_b;
	struct s_stack     *next;
}	t_stack;

typedef	struct s_data
{
	long long	*tab;
	int		values_count;
}   t_data;


//				SORT
void    sort_exec(t_stack **stack_a, t_stack **stack_b, t_data *data);
void    sort_2(t_stack **stack_a);
void    sort_3(t_stack **stack_a);
void    sort_3_instructions(t_stack **stack_a, int *tab);
void    sort_4_and_above(t_stack **stack_a, t_stack **stack_b, t_data *data);

//				SORT UTILS
t_stack		*cheapest_node(t_stack **stack_b);
int     	presort_divider(int count);
int			first_targ_pos_value(t_stack **stack_a, int index);
int			is_not_1_of_3_highest_node(t_data *data, int node_index);
void	push_presort_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data);
void    presort_push(t_stack **a, t_stack **b, t_stack *node, int size);
void    sort_a(t_stack **stack_a, t_data *data);
void    rotate_a_to_take_b_node(t_stack **stack_a, int cost_a);
void    rotate_node_to_1st(t_stack **stack, t_stack *node, int size, int id);
void    rr_or_rrr_if_possible(t_stack **stack_a, t_stack **stack_b, t_stack *node);


//				INSTRUCTIONS
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    swap_first_and_second(t_stack **stack);
void    push(t_stack **stack_from, t_stack **stack_to);

//				CHECK ARGUMENTS
int     args_are_num(char **av);
int     check_value_len(long long value);
void    set_values_int_tab(t_data *data, char **av, int ac);
void    exit_if_values_out_of_range(t_data *data);
void    exit_if_values_already_sorted(t_data *data);
void    exit_if_duplicates(t_data *data);

//				INIT LIST
t_stack	*create_node(t_data *data);
void    init_stack_a(t_stack **stack_a, t_data *data);
void    create_stack(t_stack **stack_a, t_data *data);
void    set_final_index_values(t_stack **stack_a);
void    set_nodes_values(t_stack **stack_a, t_data *data);
void    set_current_position(t_stack **stack);
void	set_b_node_a_cost(t_stack **stack_a, t_stack **stack_b,  int a_size);
void    set_a_cost(t_stack *b_node, int index, int a_size);
void    set_b_node_b_cost(t_stack **stack_b, int b_size);
int     total_positive_cost(int a_cost, int b_cost);

//				FREE
void    free_list(t_stack **stck_a);
void    free_tab_and_exit(t_data *data, int id);
void    error_free_all(t_stack **stack_a, t_data *data);
void    free_all(t_stack **stack_a, t_data *data);

//				UTILS
int		    lst_size(t_stack **lst);
long long	ft_atoi(char *nptr);


#endif
