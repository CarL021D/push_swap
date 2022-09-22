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
//	t_stack		*a_node;
//	t_stack		*b_node;
	int		stack_a_size;
	int		stack_b_size;

	stack_a_size = 3;
	stack_b_size = (data->values_count - 3);
	
	push_presort_to_b(stack_a, stack_b, data);   
	sort_3(stack_a);
	while (*stack_b)
	{
/*
		//TO DO RESET COST
		a_node = *stack_a;
		b_node = *stack_b;
		while (a_node)
		{
			set_stack_a_cost(stack_a, a_node);
			a_node = a_node->next;
		}
		while (b_node)
		{
			set_stack_b_cost(stack_b, b_node);
			b_node = b_node->next;
		}
*/
		set_current_position(stack_b);
		
	 	node = cheapest_node(stack_b);
	
		rotate_til_node_is_first(stack_b, node->index, node->current_pos, stack_b_size);
		rotate_a_to_take_b_node(stack_a, node);
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
//	rotate_til_node_is_first(stack_b, node->index,
//		node->current_pos, stack_b_size);
//	printf("cheapest node: value %d, index %d\n", node->value, node->index);
//	printf("cost : A %d, B %d\n", node->cost_a, node->cost_b);
//	(void)stack_b;
//	(void)data;
//	sort_a(stack_a, data);
}

int	presort_divider(int count)
{
	int	divider;

	if (count <= 20)
		divider = (count / 3);
	else if (count <= 50)
		divider = count / 5;
	else if (count <= 150)
		divider = count / 10;
	else
		divider = count / 20;
	return (divider);
}

// void    push_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *cpy, int size)
// {
    
// }

// void    push_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
// {
//     t_stack *cpy;

//     cpy = *stack_a;
    
// }

void	push_presort_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack		*cpy;
	int		divider;
	int		range;
	int		loop;
	int     stack_size;

	divider = presort_divider(data->values_count);
	range = divider;
	stack_size = lst_size(stack_a);
	while (range <= data->values_count)
	{
		cpy = *stack_a;
		loop = 0;
		while (cpy && (loop < divider))
		{
			if (cpy->index < range && cpy->index != data->values_count - 1 \
			&& cpy->index != data->values_count - 2 && cpy->index != data->values_count - 3)
			{
				rotate_til_node_is_first(stack_a, cpy->index, cpy->current_pos ,stack_size);
				push(stack_a, stack_b);
				write(1, "pb\n", 3);
				stack_size--;
                		set_current_position(stack_a);
                		loop++;
				cpy = *stack_a;
			}
			else
            			cpy = cpy->next;
		}
		range += divider;
	}
}




int	total_positive_cost(int a_cost, int b_cost)
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
	t_stack		*cpy;
	int		node_total_cost;
	int		cpy_total_cost;      

	node_to_push = *stack_b;
	cpy = *stack_b;
	while (cpy)
	{
		node_total_cost = total_positive_cost(node_to_push->cost_a, \
		node_to_push->cost_b);
		cpy_total_cost = total_positive_cost(cpy->cost_a, cpy->cost_b);
		if (node_total_cost > cpy_total_cost)
			node_to_push = cpy;
		cpy = cpy->next;
	}
	return (node_to_push);
}

void	rotate_a_to_take_b_node(t_stack **stack_a, t_stack *node)
{
//	printf("A COST: %d\n", node->cost_a);
	while (node->cost_a)
	{
		if (node->cost_a > 0)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
			node->cost_a--;
		}
		else
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 3);
			node->cost_a++; 
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
