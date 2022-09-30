/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:14:17 by caboudar          #+#    #+#             */
/*   Updated: 2022/10/01 00:51:51 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_exec(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	if (data->values_count == 2)
		sort_2(stack_a);
	if (data->values_count == 3)
		sort_3(stack_a);
	if (data->values_count >= 4)
		sort_4_and_above(stack_a, stack_b, data);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_data		data;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (!args_are_num(av))
	{
		exit(EXIT_FAILURE);
	}
	set_values_int_tab(&data, av, ac);
	exit_if_values_out_of_range(&data);
	if (ac == 2)
		free_tab_and_exit(&data, SUCCESS);
	exit_if_values_already_sorted(&data);
	exit_if_duplicates(&data);
	init_stack_a(&stack_a, &data);
	sort_exec(&stack_a, &stack_b, &data);
	free_all(&stack_a, &data);
}
