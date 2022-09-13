/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:14:17 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/13 02:25:10 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sort_3_values(stack_a)
{
    if (data->values_count != 3)
        return ;
    
}   

void    sort_2_values(t_stack **stack_a, t_data *data)
{
    if (data->values_count != 2)
        return ;
    swap_first_and_second(stack_a);
    write(1, "sa\n", 3);
}

void    sort(t_stack **stack_a/*, t_stack **stack_b*/, t_data *data)
{
    sort_2_values(stack_a, data);
    sort_3_values(stack_a);
}

int main(int ac, char **av)
{
    t_stack     *stack_a;
    // t_stack     *stack_b;
    t_data      data;
    
    stack_a = NULL;
    // stack_b = NULL;
    if (ac < 3 || !args_are_num(av))
        exit(EXIT_FAILURE);
    set_values_int_tab(&data, av, ac);
    check_values_range(&data);
    exit_if_values_already_sorted(&data);
    check_duplicate(&data);
    init_stack_a(&stack_a, &data);
    // init_stack_a(&stack_b, &data);

    sort(&stack_a/*, &stack_b*/, &data);
    
    free(data.values_arr);
    

    // PRINT STACKS
    // printf("\nA\n");
    // push(&stack_a, &stack_b);
    // while (stack_a)
    // {
    //     printf("%d\n", stack_a->value);
    //     stack_a = stack_a->next;
    // }
    
    // printf("\nB\n");
    // while (stack_b)
    // {
    //     printf("%d\n", stack_b->value);
    //     stack_b = stack_b->next;
    // }
}
