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

void    sort_4_and_above(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
    push_presort_to_b(stack_a, stack_b, data);   
    
     
    // sort_3(stack_a);
    // (void)stack_b;
    // (void)data;

    // sort_a(stack_a, data);
}

int     presort_divider(int count)
{
    int     divider;

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
                set_current_position(stack_a);
                loop++;
				range += divider;
			}
            cpy = cpy->next;
		}
		range += divider;
	}
}




int         total_positive_cost(int a_cost, int b_cost)
{
    int     total_pos_cost;
    
    if (a_cost < 0)
        a_cost *= -1;
    if (b_cost < 0)
        b_cost *= -1;
    total_pos_cost = a_cost + b_cost;
    return (total_pos_cost);
}

t_stack     *cheapest_node(t_stack **stack_b)
{
    t_stack     *node_to_push;
    t_stack     *cpy;
    int         node_total_cost;
    int         cpy_total_cost;      
    
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

void    rotate_a_to_take_b_node(t_stack **stack_a, t_stack *node)
{
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

void    rotate_til_node_is_first(t_stack **stack, int index, int pos, int size)
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
    t_stack     *node;
    int         rotate_nb;

    node = *stack_a;
    rotate_nb = 0;
    // printf("%d\n", (*stack_a)->value);
    while (node->index != 0)
    {
        node = node->next;
        rotate_nb++;
    }
    while ((*stack_a)->index != 0)
    {
        if (rotate_nb <= (data->values_count / 2))
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