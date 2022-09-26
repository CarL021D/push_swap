#include "../include/push_swap.h"

int	is_not_1_of_3_highest_node(t_data *data, int node_index)
{
	if (node_index != data->values_count - 1
		&& node_index != data->values_count - 2
			&& node_index != data->values_count - 3)
		return (1);
	return (0);
}

int     presort_divider(int count)
{       
        int     divider;
       
        if (count <= 150)
                divider = count / 2;
        else
                divider = count / 20;
        return (divider);
 
/*
        if (count <= 20)
                divider = (count / 3);
        else if (count <= 50)
                divider = count / 5;
        else if (count <= 150)
                divider = count / 2;
        else    
                divider = count / 20;
        return (divider);
*/
}

void	presort_push(t_stack **a, t_stack **b, t_stack *node, int size)
{
	rotate_til_node_is_first(a, node, size);
        push(a, b);
       	write(1, "pb\n", 3);
        set_current_position(a);
}

void    push_presort_to_b(t_stack **stack_a, t_stack **stack_b, t_data *data)
{       
        t_stack         *a_node;
        int             range;
        int		stack_size;
	int		loop;
        
        range = presort_divider(data->values_count);
        stack_size =  data->values_count;
        while (range <= data->values_count + 3)
        {       
                a_node = *stack_a;
		loop = 0;
                while (a_node && loop < presort_divider(data->values_count))
		{       
                        if (a_node->index < range \
			&& is_not_1_of_3_highest_node(data, a_node->index))
                        {
				presort_push(stack_a, stack_b, a_node, stack_size);
                                stack_size--;
                                a_node = *stack_a;
                        }
                        else    
                                a_node = a_node->next;
                }
		range += presort_divider(data->values_count);
        }
}
