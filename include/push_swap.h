/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:51:52 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/19 23:08:37 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
    int         value;
    int         index;
    int         current_pos;
    int         target_pos;
    int         cost_a;
    int         cost_b;
    struct s_stack     *next;
}   t_stack;

typedef struct s_data
{
    long long       *tab;
    int             values_count;
    
}   t_data;


//           SORT
void    sort_exec(t_stack **stack_a, t_stack **stack_b, t_data *data);
void    sort_2(t_stack **stack_a);
void    sort_3(t_stack **stack_a);
void    sort_3_instructions(t_stack **stack_a, int *tab);
void    sort_4_and_above(t_stack **stack_a, t_stack **stack_b, t_data *data);

//           SORT UTILS
int     presort_divider(int count);
void	push_presort_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data);
void    sort_a(t_stack **stack_a, t_data *data);
void    rotate_til_node_is_first(t_stack **stack, int index, int pos, int size);


//           INSTRUCTIONS
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    swap_first_and_second(t_stack **stack);
void    push(t_stack **stack_from, t_stack **stack_to);

//           CHECK ARGUMENTS
int     args_are_num(char **av);
int     check_value_len(long long value);
void    set_values_int_tab(t_data *data, char **av, int ac);
void    exit_if_values_already_sorted(t_data *data);
void    check_duplicate(t_data *data);
void    check_values_range(t_data *data);

//           INIT LIST
t_stack	*create_node(t_data *data);
void    init_stack_a(t_stack **stack_a, t_data *data);
void    create_stack(t_stack **stack_a, t_data *data);
void    set_final_index_values(t_stack **stack_a);
void    set_nodes_values(t_stack **stack_a, t_data *data);
void    set_current_position(t_stack **stack);
void    set_target_position(t_stack **stack_a, t_stack *node);
void    set_stack_a_cost(t_stack **stack_a, t_stack *node);
void    set_stack_b_cost(t_stack **stack_b, t_stack *node);


//           FREE
void    free_tab_and_exit(t_data *data);

//           UTILS
int		    lst_size(t_stack **lst);
long long	ft_atoi(char *nptr);


#endif