/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:51:52 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/01 22:02:53 by caboudar         ###   ########.fr       */
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
    int         pos;
    int         target_pos;
    int         cost_a;
    int         cost_b;
    struct s_stack     *next;
}   t_stack;

typedef struct s_data
{
    long long     *number_arr;
    int     values_count;
    
}   t_data;


int     args_are_num(char **av);



#endif