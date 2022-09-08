/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:13:32 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/08 14:02:03 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    set_final_index_values(t_stack **stack_1)
{
    t_stack     *node_to_set;
    t_stack     *copy;
    int         pos;

    node_to_set = *stack_1;
    while (node_to_set)
    {
        copy = *stack_1;
        pos = 0;
        // pos = 1;
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

void    set_nodes_values(t_stack **stack_1, t_data *data)
{
    t_stack     *node;
    int         i;

    node = *stack_1;
    i = 0;
    while (node)
    {
        node->value = data->values_arr[i];
        // Printf
        printf("%d\n", node->value);
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

void    set_target_position(t_stack **stack_1, t_stack *node/*, t_data *data*/)
{
    t_stack     *cpy;
    int         i;
    int         range;

    cpy = *stack_1;
    i = 0;
    range = node->index + cpy->index;
    while (cpy)
    {
        if (node->index == cpy->index + 1)
        {
            node->target_pos = i;
            printf("target_pos: %d\n", node->target_pos);
            return ;
        }
        if (node->index + cpy->index < range)
            range = node->index + cpy->index;  
        i++;
        cpy = cpy->next;
    }
    printf("target_pos: %d\n", range);
}

void    set_stack_a_cost(t_stack **stack_1, t_stack *node, t_data *data)
{
    t_stack     *cpy;
    int         cost;
    int         mid;

    (void)data;
    cpy = *stack_1;
    cost = 0;
    // lst_size
    mid = data->values_count / 2;    
    if (node->current_pos <= (mid - 1))
    {
        while (cpy)
        {
            if (node->index + 1 == cpy->index)
                break;
        
            cost = 0;
            cpy = cpy->next;
        }
    }
    node->cost_b = cost;
    printf("cost_b: %d\n", node->cost_b);

}

void    set_stack_b_cost(t_stack **stack_2, t_stack *node, t_data *data)
{
    t_stack     *cpy;
    int         cost;
    int         mid;


    // lst->size
    mid = (data->values_count / 2);
    if (node->current_pos <= (mid - 1))
    {
        cpy = *stack_2;
        cost = 0;
        while (cpy != node)
        {
            cost++;
            cpy = cpy->next;
        }   
    }
    else
    {
        cpy = node;
        cost = 1;      
        while (cpy->next)
        {    
            cost++;
            cpy = cpy->next;
        }
    }
    node->cost_b = cost;
    printf("cost_b: %d\n", node->cost_b);
}