/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:17:11 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/19 21:12:02 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// ra, rb
void    rotate(t_stack **stack)
{
    t_stack     *node;
    t_stack     *cpy;

    node = *stack;
    cpy = *stack;
    *stack = (*stack)->next;
    while (cpy->next)
        cpy = cpy->next;
    cpy->next = node;
    node->next = NULL;    
}

// rra, rrb
void    reverse_rotate(t_stack **stack)
{
    t_stack     *node;
    t_stack     *cpy;
    int         size;

    node = *stack;
    cpy = *stack;
    size = lst_size(stack);
    while (size - 2)
    {
        node = node->next;
        size--;
    }
    cpy = node->next;
    cpy->next = *stack;
    *stack = cpy;
    node->next = NULL;
}

// sa, sb
void    swap_first_and_second(t_stack **stack)
{
    t_stack     *node;

    node = (*stack)->next;
    (*stack)->next = node->next;
    node->next = *stack;
    *stack = node;
}

// pa , pb
void    push(t_stack **stack_from, t_stack **stack_to)
{
    t_stack     *node;

    node = *stack_from;
    *stack_from = (*stack_from)->next;
    node->next = *stack_to;
    *stack_to = node;
}