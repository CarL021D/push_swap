/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_and_above_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:02:41 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/26 18:20:09 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	presort_push(t_stack **a, t_stack **b, t_stack *node, int size)
{
	rotate_til_b_node_is_first(a, node, size);
        push(a, b);
       	write(1, "pb\n", 3);
        set_current_position(a);
}

int     total_positive_cost(int a_cost, int b_cost)
{       
	int	total_pos_cost;

	if (a_cost < 0)
		a_cost *= -1;
	if (b_cost < 0)
		b_cost *= -1;
	total_pos_cost = a_cost + b_cost;
	return (total_pos_cost);
}

t_stack		*cheapest_node(t_stack **stack_b)
{
	t_stack		*node_to_push;
	t_stack		*b_node;
	int		saved_total_cost;
	int		b_node_cost;

	node_to_push = *stack_b;
	b_node = *stack_b;
	saved_total_cost = total_positive_cost((*stack_b)->cost_a,
		(*stack_b)->cost_b);
	while (b_node)
	{
		b_node_cost = total_positive_cost(b_node->cost_a, b_node->cost_b);
		if (b_node_cost < saved_total_cost)
		{
			saved_total_cost = b_node_cost;
			node_to_push = b_node;	
		}
		b_node = b_node->next;
	}
	return (node_to_push);
}

void	rotate_a_to_take_b_node(t_stack **stack_a, int cost_a)
{
	while (cost_a)
	{
		if (cost_a > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			cost_a--;
		}
		else
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
			cost_a++; 
		}
	}
}

void	rotate_til_b_node_is_first(t_stack **stack, t_stack *node, int size)
{
	while ((*stack)->index != node->index)
	{
		if (node->current_pos <= (size / 2))
		{
			rotate(stack);
			write(1, "rb\n", 3);
		}
		else
		{
			reverse_rotate(stack);
			write(1, "rrb\n", 4); 
		}
	}
}
