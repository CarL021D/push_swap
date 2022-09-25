/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_and_above.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:35:50 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/20 02:48:25 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_4_and_above(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack		*node;
	int		a_size;
	int		b_size;

	a_size = 3;
	b_size = (data->values_count - 3);
	push_presort_to_b(stack_a, stack_b, data);   
	sort_3(stack_a);
	while (*stack_b)
	{
		set_current_position(stack_b);
		set_b_node_a_cost(stack_a, stack_b, a_size);
		set_b_node_b_cost(stack_b, b_size);
	 	node = cheapest_node(stack_b);
		rotate_til_node_is_first(stack_b, node->index, node->current_pos, b_size);
		rotate_a_to_take_b_node(stack_a, node->cost_a);
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
		a_size++;
		b_size--;
	}
	sort_a(stack_a, data);
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

void	rotate_til_node_is_first(t_stack **stack, int index, int pos, int size)
{
	while ((*stack)->index != index)
	{
		if (pos <= (size / 2))
		{
			rotate(stack);
			write(1, "ra\n", 3);
		}
		else
		{
			reverse_rotate(stack);
			write(1, "rra\n", 4); 
		}
	}
}

void    sort_a(t_stack **stack_a, t_data *data)
{
	t_stack		*node;
	int		rotate_count;

	node = *stack_a;
	rotate_count = 0;
	while (node->index != 0)
	{
		node = node->next;
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
