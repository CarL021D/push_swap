/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:13:32 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/19 20:10:52 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    init_stack_a(t_stack **stack_a, t_data *data)
{
    create_stack(stack_a, data);
    set_nodes_values(stack_a, data);
    set_final_index_values(stack_a);
    set_current_position(stack_a);
}

// void    update_stack_values(t_stack stack);
// {
//     set_current_position(stack);
// }
// void    set_final_index_values(t_stack **stack_1)
// {
//     t_stack     *node_to_set;
//     t_stack     *copy;
//     int         pos;

//     node_to_set = *stack_1;
//     while (node_to_set)
//     {
//         copy = *stack_1;
//         pos = 0;
//         while (copy)
//         {
//             if (copy->value < node_to_set->value)
//                 pos++;
//             copy = copy->next;
//         }
//         node_to_set->index = pos;
//         node_to_set = node_to_set->next;
//     }
// }

// void    set_nodes_values(t_stack **stack_1, t_data *data)
// {
//     t_stack     *node;
//     int         i;

//     node = *stack_1;
//     i = 0;
//     while (node)
//     {
//         node->value = data->values_arr[i];

//         // Printf
//         printf("%d\n", node->value);
//         node = node->next;
//         i++;
//     }
// }

// void    set_current_position(t_stack **stack)
// {
//     t_stack     *node;
//     int         i;

//     node = *stack;
//     i = 0;
//     while (node)
//     {
//         node->current_pos = i;
//         i++;
//         node = node->next;
//     }
// }