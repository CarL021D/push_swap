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

void	set_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*a_node;
	t_stack		*b_node;
	int		targ_pos;
	int		range;
	
	b_node = *stack_b;
	if ((*stack_a)->index - (*stack_b)->index)
		range = (*stack_a)->index - (*stack_b)->index;
	while (b_node)
	{
		a_node = *stack_a;
		targ_pos = 0;
		while (a_node)
		{
			if (b_node->index + 1 == a_node->index)	
			{
				b_node->target_pos = targ_pos;
				break;
			}
			if (a_node->index - b_node->index < range \
			&& a_node->index - b_node->index > 0)
			{
				b_node->target_pos = targ_pos;
				range = a_node->index - b_node->index;
			}
			targ_pos++;
		}
		b_node = b_node->next;
	}


/*
	t_stack		*cpy;
	int		i;
	int		range;
	int		current_range;
	int		target_index;

	cpy = *stack_a;
	i = 0;
	range = cpy->index - node->index;
	current_range = 0;
	while (cpy)
	{
		if (node->index + 1 == cpy->index)
		{
			node->target_pos = i;
			return ;
		}
		current_range = cpy->index - node->index;
		if (current_range < range && current_range > 0)
		{
			node->target_pos = i;
			range = cpy->index - node->index;  
		}
		i++;
		cpy = cpy->next;
	}
*/
}

void    set_stack_a_cost(t_stack **stack_b, int a_size)
{
	t_stack     *b_node;

	b_node = *stack_b;
	while (b_node)
	{
		if (b_node->target_pos <= a_size / 2)
			b_node->cost_a = target_pos;
		else
			b_node->cost_a = a_size - target_pos;
		b_node = b_node->next;
	}

/*
	b_node = *stack_b;
	mid = lst_size(stack_b) / 2;
	while (b_node)
	{
		if (cpy->current_pos < mid)
			cpy->cost_a = cpy->target_pos;
		else
		{
			tmp = *stack_b;
			i = 0;
			while (i < cpy->target_pos)
			{
				i++;
				tmp = tmp->next;
			}
			i = 0;
			while (tmp->next)
			{
				i++;
				tmp = tmp->next;
			}
			i++;
        		i *= -1;
			node->cost_a = i;
		}
		b_node = b_node->next;
	}
	printf("cost_a: %d\n", node->cost_a);
*/
}

void    set_stack_b_cost(t_stack **stack_b, int b_size)
{
	t_stack     *b_node;
	t_stack     *cpy;
	int         cost;
//  	int         mid;

//	mid = (lst_size(stack_b) / 2);
	b_node = *stack_b;
	while (b_node)
	{
		cpy = *stack_b;
		cost = 0;
//		if (node->current_pos <= b_size / 2)
//		{
//			cpy = *stack_b;
			while (cpy->index != b_node->index)
			{
				cost++;
				cpy = cpy->next;
			}
//		}
		if (b_node->current_pos > b_size / 2)
		{
			cost = 0;
			while (cpy->next)
			{
				cost++;
				cpy = cpy->next;
			}
			cost++;
        		cost *= -1;
		}
	}
	b_node->cost_b = cost;
	printf("cost_b: %d\n", node->cost_b);
}
