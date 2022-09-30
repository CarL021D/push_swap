/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_and_above_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:02:53 by caboudar          #+#    #+#             */
/*   Updated: 2022/10/01 00:25:28 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	presort_push(t_stack **a, t_stack **b, t_stack *node, int size)
{
	rotate_node_to_1st(a, node, size, STACK_A);
	push(a, b);
	write(1, "pb\n", 3);
	set_current_position(a);
}

int	is_not_1_of_3_highest_node(t_data *data, int node_index)
{
	if (node_index != data->values_count - 1
		&& node_index != data->values_count - 2
		&& node_index != data->values_count - 3)
		return (1);
	return (0);
}

int	presort_divider(int count)
{
	int		divider;

	if (count <= 100)
		divider = count / 2;
	else if (count <= 250)
		divider = count / 3;
	else
		divider = count / 4;
	return (divider);
}

void	push_presort_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack		*a_node;
	int			range;
	int			stack_size;
	int			loop;

	range = presort_divider(data->values_count);
	stack_size = data->values_count;
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

void	sort_a(t_stack **stack_a, t_data *data)
{
	t_stack		*a_node;
	int			rotate_count;

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
