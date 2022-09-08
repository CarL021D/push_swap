/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:26:22 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/05 20:26:39 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int args_are_num(char **av)
{
    int     i;
    int     j;
        
    i = 1;
    while (av[i])
    {
        j = 0;
        if (av[i][j] == '-' || av[i][j] == '+')
            j++;
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

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

void    exit_if_values_already_sorted(t_data *data)
{
    int     i;
    int     value_count;

    i = 0;
    value_count = data->values_count - 1;
    while (value_count && data->values_arr[i] < data->values_arr[i + 1])
    {
        i++;
        value_count--;
    }
    if (value_count == 0)
    {
        // Printf
        printf("sorted\n");
        free_tab_and_exit(data);
    }
}

int     check_value_len(long long value)
{
    int     i;
    long long   num_copy;
    
    i = 0;
    num_copy = value;
    while (num_copy)
    {
        num_copy /= 10;
        i++;
    }
    return (i);
}