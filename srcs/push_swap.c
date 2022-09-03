/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:14:17 by caboudar          #+#    #+#             */
/*   Updated: 2022/09/03 18:56:45 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// t_stack	*ft_lstnew(void *content)
// {
// 	t_stack	*node;

// 	node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return (NULL);
// 	node->next = NULL;
// 	return (node);
// }gc

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

void    free_tab_and_exit(t_data *data)
{
    free(data->number_arr);
    exit(EXIT_FAILURE);
}


long long	ft_atoi(char *nptr)
{
	long long	res;
	int	sign;

    
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
    while (*nptr == '0')
    {
        nptr++;
    }
    res = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - 48;
		nptr++;
	}
	return (sign * res);
}

int args_are_num(char **av)
{
    int     i;
    int     j;
        
    i = 1;
    while (av[i])
    {
        j = 0;
        if (av[i][j] == '-' || av[i][j] == '+')
            j++;
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

void     set_values_int_tab(t_data *data, char **av, int ac)
{
    int     i;
    int     j;
    
    i = 1;
    j = 0;
    
    data->values_count = ac - 1;
    data->number_arr = malloc(sizeof(int *) * data->values_count);
    if (!data->number_arr)
        exit(EXIT_FAILURE);
    while (--ac)
        data->number_arr[j++] = ft_atoi(av[i++]);
}

void    exit_if_values_already_sorted(t_data *data)
{
    int     i;
    int     value_count;

    i = 0;
    value_count = data->values_count - 1;
    while (value_count && data->number_arr[i] < data->number_arr[i + 1])
    {
        i++;
        value_count--;
    }
    if (value_count == 0)
    {
        printf("sorted\n");
        free_tab_and_exit(data);
    }
}

int     check_value_len(long long value)
{
    int     i;
    long long   num_copy;
    
    i = 0;
    num_copy = value;
    while (num_copy)
    {
        num_copy /= 10;
        i++;
    }
    return (i);
}


void    check_values_range(t_data *data)
{
    int     i;
    int     value_count;
    int     value_len;

    i = 0;
    value_count = data->values_count;
    while (value_count)
    {
        value_len = check_value_len(data->number_arr[i]);
        if (value_len > 10)
        {
            printf("value len to long\n");
            free_tab_and_exit(data);
        }
        if (data->number_arr[i] < INT_MIN || data->number_arr[i] > INT_MAX)
        {
            printf("out of range\n");
            free_tab_and_exit(data);
        }
        i++;
        value_count--;
    }
}

void    check_duplicate(t_data *data)
{
    int     i;
    int     j;
    
    i = 0;
    while (i < data->values_count - 1)
    {
        j = i + 1;
        while (j < data->values_count)
        {
            if (data->number_arr[i] == data->number_arr[j])
            {
                printf("duplicate\n");
                free_tab_and_exit(data);
            }
            j++;
        }
        i++;
    }
    printf("no duplicate\n");
}

t_stack	*ft_lstnew(void)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}



void    create_and_init_mode(t_stack *stack_1, t_data *data)
{
    int     i;
    
    i = 0;
    stack_1 = ft_lstnew();
    while (i < data->values_count)
    {
        

        i++;
    }
}

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
    
    create_and_init_mode(stack_1, &data);
}
