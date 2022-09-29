/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:20:35 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/29 21:02:55 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node(t_data *data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		free(data->tab);
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	return (node);
}

void	create_stack(t_stack **stack_a, t_data *data)
{
	t_stack		*node;
	int			i;

	i = 1;
	node = create_node(data);
	*stack_a = node;
	while (i < data->values_count)
	{
		node = *stack_a;
		while (node->next)
			node = node->next;
		node->next = create_node(data);
		i++;
	}
}
