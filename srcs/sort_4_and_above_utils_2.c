/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_and_above_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:02:53 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/26 18:20:15 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_not_1_of_3_highest_node(t_data *data, int node_index)
{
	if (node_index != data->values_count - 1
		&& node_index != data->values_count - 2
			&& node_index != data->values_count - 3)
		return (1);
	return (0);
}

int     presort_divider(int count)
{       
        int     divider;
       
        if (count <= 150)
                divider = count / 2;
        else
                divider = count / 20;
        return (divider);
 
/*
        if (count <= 20)
                divider = (count / 3);
        else if (count <= 50)
                divider = count / 5;
        else if (count <= 150)
                divider = count / 2;
        else    
                divider = count / 20;
        return (divider);
*/
}

void    push_presort_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{       
        t_stack         *a_node;
        int             range;
        int		stack_size;
	int		loop;
        
        range = presort_divider(data->values_count);
        stack_size =  data->values_count;
        while (range <= data->values_count + 3)
        {       
                a_node = *stack_a;
		loop = 0;
                while (a_node && loop < presort_divider(data->values_count))
		{       
                        if (a_node->index < range \
			&& is_not_1_of_3_highest_node(data, a_node->index))
                        {
				presort_push(stack_a, stack_b, a_node, stack_size);
                                stack_size--;
                                a_node = *stack_a;
                        }
                        else    
                                a_node = a_node->next;
                }
		range += presort_divider(data->values_count);
        }
}

void    sort_a(t_stack **stack_a, t_data *data)
{
	t_stack		*a_node;
	int		rotate_count;

	a_node = *stack_a;
	rotate_count = 0;
	while (a_node->index != 0)
	{
		a_node = a_node->next;
		rotate_count++;
	}
	while ((*stack_a)->index != 0)
	{
		if (rotate_count <= (data->values_count / 2))
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
		}
	}
}

void	rr_or_rrr_if_possible(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	if (node->cost_a > 0 && node->cost_b > 0)
	{
		while (node->cost_a > 0 && (*stack_b)->index != node->index)
		{
			rotate(stack_a);
			rotate(stack_b);
			write(1, "rr\n", 3);
			node->cost_a--;
		}
	}
	if (node->cost_a < 0 && node->cost_b < 0)
	{	
		while (node->cost_a < 0 && (*stack_b)->index != node->index)
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
			write(1, "rrr\n", 4);
			node->cost_a++;
		}
	}	
}