/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:40:54 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/29 00:27:30 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_list(t_stack **stack_a)
{
	t_stack		*a_node;

	while (*stack_a)
	{
		a_node = (*stack_a)->next;
		free(*stack_a);
		*stack_a = a_node;
	}
}

void    free_tab_and_exit(t_data *data, int id)
{
	free(data->tab);
	if (id == 1)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void	free_all(t_stack **stack_a, t_data *data)
{
	free_list(stack_a);
	free(data->tab);
	exit(EXIT_SUCCESS);
}
