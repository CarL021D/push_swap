/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:22:44 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/14 00:23:40 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void     init_tab_of_3(t_stack **stack_a, t_data *data)
{
    t_stack     *cpy;
    int         i;

    cpy = *stack_a;
    i = 0;
    data->tab_3 = malloc(sizeof(int *) * 3);
    if (!data->tab_3)
        free_tab_and_exit(data);
    while (cpy)
    {
        data->tab_3[i] = cpy->index;
        i++;
        cpy = cpy->next;
    }
}

void    sort_3(t_stack **stack_a, t_data *data)
{
    init_tab_of_3(stack_a, data);
    if ((data->tab_3[0] < data->tab_3[2] && data->tab_3[2] < data->tab_3[1])
        || (data->tab_3[1] < data->tab_3[0] && data->tab_3[0] < data->tab_3[2])
        || (data->tab_3[2] < data->tab_3[1] && data->tab_3[1] < data->tab_3[0]))
    {
        swap_first_and_second(stack_a);
        write(1, "sa\n", 3);
    }
    if ((data->tab_3[0] < data->tab_3[2] && data->tab_3[2] < data->tab_3[1])
        || (data->tab_3[1] < data->tab_3[2] && data->tab_3[2] < data->tab_3[0]))
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
    }
    if ((data->tab_3[2] < data->tab_3[0] && data->tab_3[0] < data->tab_3[1])
        || (data->tab_3[2] < data->tab_3[1] && data->tab_3[1] < data->tab_3[0]))
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 4);
    }  
}  