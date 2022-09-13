/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_and_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:24:31 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/14 01:04:10 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort_2(t_stack **stack_a)
{
    swap_first_and_second(stack_a);
    write(1, "sa\n", 3);
    // TO DO
    // free tab of values + lst
}

void    sort_3(t_stack **stack_a, t_data *data)
{
    if ((data->tab[0] < data->tab[2] && data->tab[2] < data->tab[1])
        || (data->tab[1] < data->tab[0] && data->tab[0] < data->tab[2])
        || (data->tab[2] < data->tab[1] && data->tab[1] < data->tab[0]))
    {
        swap_first_and_second(stack_a);
        write(1, "sa\n", 3);
    }
    if ((data->tab[0] < data->tab[2] && data->tab[2] < data->tab[1])
        || (data->tab[1] < data->tab[2] && data->tab[2] < data->tab[0]))
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
    }
    if ((data->tab[2] < data->tab[0] && data->tab[0] < data->tab[1])
        || (data->tab[2] < data->tab[1] && data->tab[1] < data->tab[0]))
    {
        reverse_rotate(stack_a);
        write(1, "rra\n", 4);
    }
    // TO DO
    // free tab of values
}  
