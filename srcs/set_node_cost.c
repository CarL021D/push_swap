/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:03:04 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/26 18:09:48 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_a_cost(t_stack *b_node, int index, int a_size)
{
	if (index <= a_size / 2)
		b_node->cost_a = index;
	else    
 		b_node->cost_a = -(a_size - index);
}

void    set_b_node_a_cost(t_stack **stack_a, t_stack **stack_b, int a_size)
{
        t_stack         *a_node;
        t_stack         *b_node;
        int             range;
        int             i;

        b_node = *stack_b;
        while (b_node)
        {
                a_node = *stack_a;
                range = first_targ_pos_value(stack_a, b_node->index);
                i = 0;
                while (a_node)
                {
                        if (a_node->index - b_node->index <= range
                                && a_node->index - b_node->index > 0)
                        {
                                range = a_node->index - b_node->index;
				set_a_cost(b_node, i, a_size);
                                if (i <= a_size / 2)
                                       b_node->cost_a = i;
                              else
                                        b_node->cost_a = -(a_size - i);
                        }
                        i++;
                        a_node = a_node->next;
                }
                b_node = b_node->next;
        }
}

void    set_b_node_b_cost(t_stack **stack_b, int b_size)
{
        t_stack     *b_node;

	b_node = *stack_b;
	while (b_node)
        {
                if (b_node->current_pos <= b_size / 2)
                        b_node->cost_b = b_node->current_pos;
                else
                        b_node->cost_b = -(b_size - b_node->current_pos);
                b_node = b_node->next;
        }
}
