/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:13:32 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/26 18:03:31 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    init_stack_a(t_stack **stack_a, t_data *data)
{
    create_stack(stack_a, data);
    set_nodes_values(stack_a, data);
    set_final_index_values(stack_a);
    set_current_position(stack_a);
}
