/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:26:22 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/14 00:58:02 by caboudar         ###   ########.fr       */
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

void    exit_if_values_already_sorted(t_data *data)
{
    int     i;
    int     value_count;

    i = 0;
    value_count = data->values_count - 1;
    while (value_count && data->tab[i] < data->tab[i + 1])
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

void    check_values_range(t_data *data)
{
    int     i;
    int     value_count;
    int     value_len;

    i = 0;
    value_count = data->values_count;
    while (value_count)
    {
        value_len = check_value_len(data->tab[i]);
        if (value_len > 10)
        {
            // Printf
            printf("value len to long\n");
            free_tab_and_exit(data);
        }
        if (data->tab[i] < INT_MIN || data->tab[i] > INT_MAX)
        {
            // Printf
            printf("out of range\n");
            free_tab_and_exit(data);
        }
        i++;
        value_count--;
    }
}

void    check_duplicate(t_data *data)
{
    int     i;
    int     j;
    
    i = 0;
    while (i < data->values_count - 1)
    {
        j = i + 1;
        while (j < data->values_count)
        {
            if (data->tab[i] == data->tab[j])
            {
                // Printf
                printf("duplicate\n");
                free_tab_and_exit(data);
            }
            j++;
        }
        i++;
    }
    // Printf
    printf("no duplicate, not sorted\n");
}