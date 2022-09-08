/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:51:52 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/08 14:20:08 by caboudar         ###   ########.fr       */
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
    long long     *values_arr;
    int     values_count;
    
}   t_data;

//           CHECK ARGUMENTS
int     args_are_num(char **av);
int     check_value_len(long long value);
void    set_values_int_tab(t_data *data, char **av, int ac);
void    exit_if_values_already_sorted(t_data *data);
void    check_duplicate(t_data *data);
void    check_values_range(t_data *data);

//            INIT LIST
t_stack	*create_node();
void    init_stack_1(t_stack **stack_1, t_data *data);
void    create_stack_1(t_stack **stack_1, t_data *data);
void    set_final_index_values(t_stack **stack_1);
void    set_nodes_values(t_stack **stack_1, t_data *data);
void    set_current_position(t_stack **stack);
void    set_target_position(t_stack **stack_1, t_stack *node);
void    set_stack_a_cost(t_stack **stack_1, t_stack *node);
void    set_stack_b_cost(t_stack **stack_2, t_stack *node);


//            FREE
void    free_tab_and_exit(t_data *data);

//            UTILS
int		    lst_size(t_stack **lst);
long long	ft_atoi(char *nptr);


#endif