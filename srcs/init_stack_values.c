/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:13:32 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/14 01:45:40 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    set_final_index_values(t_stack **stack_a)
{
	t_stack		*node_to_set;
	t_stack		*a_node;
	int		pos;

	node_to_set = *stack_a;
	while (node_to_set)
	{
		a_node = *stack_a;
		pos = 0;
		while (a_node)
		{
			if (a_node->value < node_to_set->value)
				pos++;
			a_node = a_node->next;
		}
		node_to_set->index = pos;
		node_to_set = node_to_set->next;
	}
}

void	set_nodes_values(t_stack **stack_a, t_data *data)
{
	t_stack		*node;
	int		i;

	node = *stack_a;
	i = 0;
	while (node)
	{
		node->value = data->tab[i];
		node = node->next;
		i++;
	}
}

void	set_current_position(t_stack **stack)
{
	t_stack		*node;
	int		i;

	node = *stack;
	i = 0;
	while (node)
	{
		node->current_pos = i;
		i++;
		node = node->next;
	}
}

int	first_targ_pos_value(t_stack **stack_a, int index)
{
	t_stack		*a_node;
	int		i;

	a_node = *stack_a;
	i = 0;
	while (a_node)
	{
		if (a_node->index - index > 0)
			break ;
		i++;
		a_node = a_node->next;
	}
	return (a_node->index - index);
}
