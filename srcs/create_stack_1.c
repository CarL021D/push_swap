/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_init_stack_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:20:35 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/05 20:58:53 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node()
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}

void    create_stack_1(t_stack **stack_1, t_data *data)
{
    t_stack     *node;
    int         i;
    
    i = 1;
    node = create_node();
    *stack_1 = node;
    while (i < data->values_count)
    {
        node = *stack_1;
        while (node->next)
            node = node->next;
        node->next = create_node();
        i++;
    }
}