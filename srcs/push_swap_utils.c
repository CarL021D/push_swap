/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:27:24 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/08 14:20:15 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		lst_size(t_stack **lst)
{
	t_stack		*node;
	int			i;

	node = *lst;
	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

long long	ft_atoi(char *nptr)
{
	long long	res;
	int	        sign;

	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
    while (*nptr == '0')
    {
        nptr++;
    }
    res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	return (sign * res);
}