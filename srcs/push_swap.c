/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:14:17 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/19 23:28:12 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort_exec(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
    if (data->values_count == 2)
        sort_2(stack_a);
    if (data->values_count == 3)
        sort_3(stack_a);
    if (data->values_count >= 4)
        sort_4_and_above(stack_a, stack_b, data);
}

int main(int ac, char **av)
{
    t_stack     *stack_a;
    t_stack     *stack_b;
    t_data      data;
    
    stack_a = NULL;
    stack_b = NULL;
    if (ac < 3 || !args_are_num(av))
        exit(EXIT_FAILURE);
    set_values_int_tab(&data, av, ac);
    check_values_range(&data);
    exit_if_values_already_sorted(&data);
    check_duplicate(&data);
    init_stack_a(&stack_a, &data);

    sort_exec(&stack_a, &stack_b, &data);
    
    // TO DO
    // free(data.values_arr);
    // free(data.tab_3);
    

    // PRINT STACKS
    printf("\nA\n\n");
    // push(&stack_a, &stack_b);
    while (stack_a)
    {
        printf("%d -> %d\n", stack_a->index, stack_a->value);
        stack_a = stack_a->next;
    }
    
    printf("\nB\n");
    while (stack_b)
    {
        printf("%d -> %d\n", stack_b->index, stack_b->value);
        printf("Target position  >> %d\n", stack_b->target_pos);
        printf("A_cost: %d - B_cost: %d\n\n", stack_b->cost_a, stack_b->cost_b);
        stack_b = stack_b->next;
    }
}
