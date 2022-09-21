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
    t_stack     *node_to_set;
    t_stack     *copy;
    int         pos;

    node_to_set = *stack_a;
    while (node_to_set)
    {
        copy = *stack_a;
        pos = 0;
        while (copy)
        {
            if (copy->value < node_to_set->value)
                pos++;
            copy = copy->next;
        }
        node_to_set->index = pos;
        node_to_set = node_to_set->next;
    }
}

void    set_nodes_values(t_stack **stack_a, t_data *data)
{
    t_stack     *node;
    int         i;

    node = *stack_a;
    i = 0;
    while (node)
    {
        node->value = data->tab[i];
        // printf("%d\n", node->value);
        node = node->next;
        i++;
    }
}

void    set_current_position(t_stack **stack)
{
    t_stack     *node;
    int         i;

    node = *stack;
    i = 0;
    while (node)
    {
        node->current_pos = i;
        i++;
        node = node->next;
    }
}

int	set_target_position(t_stack **stack_a, t_stack *node)
{
	t_stack		*cpy;
	int		i;
	int		range;
	int		current_range;
	int		target_index;

	cpy = *stack_a;
	i = 0;
	range = cpy->index - node->index;
	current_range = 0;
	target_index = cpy->index;
	while (cpy)
	{
		if (node->index == cpy->index + 1)
		{
			node->target_pos = i;
			target_index = cpy->index;
			return (cpy->index);
		}
		current_range = cpy->index - node->index;
		if (current_range < range && current_range >= 0)
		{
			node->target_pos = i;
			range = cpy->index - node->index;  
		}
		i++;
		cpy = cpy->next;
	}
	return (cpy->index);
}

void    set_stack_a_cost(t_stack **stack_a, t_stack *node)
{
    t_stack     *cpy;
    int         i;
    int         mid;

    cpy = *stack_a;
    mid = lst_size(stack_a) / 2;    
    if (node->current_pos <= (mid - 1))
        node->cost_a = node->target_pos;
    else
    {
        i = 0;
        while (i < node->target_pos)
        {
            i++;
            cpy = cpy->next;
        }
        i = 1;
        while (cpy)
        {
            i++;
            cpy = cpy->next;
        }
        i *= -1;
        node->cost_a = i;
    }
    printf("cost_a: %d\n", node->cost_a);
}

void    set_stack_b_cost(t_stack **stack_b, t_stack *node)
{
    t_stack     *cpy;
    int         cost;
    int         mid;

	cost = 0;
	mid = (lst_size(stack_b) / 2);
	if (node->current_pos <= mid)
	{
		cpy = *stack_b;
		while (cpy->index != node->index)
		{
			cost++;
			cpy = cpy->next;
		}
	}
	else
	{
		cpy = node;
		while (cpy->next)
		{
			cost++;
			cpy = cpy->next;
		}
		cost++;
        	cost *= -1;
	}
	node->cost_b = cost;
	printf("cost_b: %d\n", node->cost_b);
}
