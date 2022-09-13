/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:03:29 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/13 02:04:10 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void     set_values_int_tab(t_data *data, char **av, int ac)
{
    int     i;
    int     j;
    
    i = 1;
    j = 0;
    
    data->values_count = ac - 1;
    data->values_arr = malloc(sizeof(int *) * data->values_count);
    if (!data->values_arr)
        exit(EXIT_FAILURE);
    while (--ac)
        data->values_arr[j++] = ft_atoi(av[i++]);
}