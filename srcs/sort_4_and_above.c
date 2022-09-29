/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_and_above.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:35:50 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/29 21:07:21 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_4_and_above(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack		*node;
	int			a_size;
	int			b_size;

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
		rr_or_rrr_if_poss(stack_a, stack_b, node);
		rotate_node_to_1st(stack_b, node, b_size, STACK_B);
		rotate_a_to_take_b_node(stack_a, node->cost_a);
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
		a_size++;
		b_size--;
	}
	sort_a(stack_a, data);
}
