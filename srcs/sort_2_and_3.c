/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_and_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:24:31 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/29 21:15:40 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_stack **stack_a)
{
	swap_first_and_second(stack_a);
	write(1, "sa\n", 3);
}

void	sort_3_instructions(t_stack **stack_a, int *tab)
{
	if ((tab[0] < tab[2] && tab[2] < tab[1])
		|| (tab[1] < tab[0] && tab[0] < tab[2])
		|| (tab[2] < tab[1] && tab[1] < tab[0]))
	{
		swap_first_and_second(stack_a);
		write(1, "sa\n", 3);
	}
	if ((tab[0] < tab[2] && tab[2] < tab[1])
		|| (tab[1] < tab[2] && tab[2] < tab[0]))
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	if ((tab[2] < tab[0] && tab[0] < tab[1])
		|| (tab[2] < tab[1] && tab[1] < tab[0]))
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
}

void	sort_3(t_stack **stack_a)
{
	t_stack		*a_node;
	int			*tab;
	int			i;

	a_node = *stack_a;
	tab = malloc(sizeof(int) * 3);
	if (!tab)
		free(tab);
	i = 0;
	while (a_node)
	{
		tab[i] = a_node->value;
		i++;
		a_node = a_node->next;
	}
	sort_3_instructions(stack_a, tab);
	free(tab);
}
