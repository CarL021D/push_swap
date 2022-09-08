/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:14:17 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/08 13:11:49 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// t_stack	*create_node(void *content)
// {
// 	t_stack	*node;

// 	node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return (NULL);
// 	node->next = NULL;
// 	return (node);
// }

// void	ft_lstadd_front(t_stack **lst, t_stack *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

// void	ft_lstadd_back(t_stack **lst, t_stack *new)
// {
// 	t_stack	*node;

// 	if (!lst || !new)
// 		return ;
// 	if (!(*lst))
// 	{
// 		*lst = new;
// 		(*lst)->next = NULL;
// 	}
// 	else
// 	{
// 		node = (*lst);
// 		while (node->next)
// 			node = node->next;
// 		node->next = new;
// 	}
// }

// int    set_stack_len(t_stack **stack, t_data *data)
// {
//     t_stack     *cpy;
//     int         len;

//     cpy = *stack;
//     len = 0;
//     while (cpy)
//     {
//         len++;
//         cpy = cpy->next;
//     }
//     return (len);
// }

int main(int ac, char **av)
{
    t_stack     *stack_1;
    // t_stack     *stack_2;
    t_data      data;
    
    if (ac < 3 || !args_are_num(av))
        exit(EXIT_FAILURE);
    set_values_int_tab(&data, av, ac);
    check_values_range(&data);
    exit_if_values_already_sorted(&data);
    check_duplicate(&data);

    
    stack_1 = NULL;
    // stack_2 = NULL;
    init_stack_1(&stack_1, &data);






    t_stack *cpy2;
    cpy2 = stack_1;
    t_stack *cpy3;
    // cpy3->target_pos = 3;
    cpy3 = malloc(sizeof(t_stack));
    cpy3->index = 0;
    cpy3->value = 1;
    set_target_position(&stack_1, cpy2);

    // while (cpy2)
    // {        // set_stack_a_cost(&stack_1, cpy3, &data);
    //     // set_stack_b_cost(&stack_1, cpy2, &data);
    //     cpy2 = cpy2->next; 
    // }

    printf("\n");
    int c = 0;
    t_stack *cpy;
    cpy = stack_1;
    while (c < data.values_count)
    {
        printf("value: %d, index: %d, current position: %d, b_cost: %d\n", cpy->value, cpy->index, cpy->current_pos, cpy->cost_b);
        c++;
        cpy = cpy->next;
    }
}

// target pos: position dans A de l index qui suit l'index du nombre qu'on veut bouger (qui est dans B)

// cost_a nombre de rr ou r pour preparer A acceuillir le nombre a bouger
//        le nombrede rr r dans A pour acceuillr B avant l index qui suit

// cost B nombre de rr ou r pour passer a la pos 0
