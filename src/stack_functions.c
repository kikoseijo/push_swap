/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:16:02 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/06/01 08:45:06 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** This function gets the best median out of the array
** This function ¡¡¡ DOES NOT WORKS !!!
*/

void	get_median(t_stack *stack, int sum, int len)
{
	int	i;
	int	*arr;
	int	median;

	i = 0;
	median = sum / len;
	arr = stack->stack;
	stack->median = arr[0];
	while (i < len)
	{
		if (median - arr[i] < median - stack->median)
			stack->median = arr[i];
		i++;
	}
}

/*
** This function finds max and min values;
** prepares the sum for get_median;
*/

void	stack_max_min(t_stack *stack)
{
	int	i;
	int	sum;

	i = 1;
	sum = 0;
	stack->min = stack->stack[0];
	stack->max = stack->stack[0];
	while (i < stack->len)
	{
		if (stack->min > stack->stack[i])
			stack->min = stack->stack[i];
		if (stack->max < stack->stack[i])
			stack->max = stack->stack[i];
		sum += stack->stack[i];
		i++;
	}
}

static void	initialize_sorted_stack(t_model *model, t_stack *stack)
{
	int		i;
	t_stack	*stack_a;

	stack_a = model->stack_a;
	stack->stack = (int *)malloc((stack_a->len) * sizeof(int));
	i = 0;
	while (i < stack_a->len)
	{
		stack->stack[i] = stack_a->stack[i];
		i++;
	}
	stack->len = stack_a->len;
}

/*
** Creates a sorted array to compare with final array;
*/

void	manual_sort(t_model *model)
{
	int		i;
	int		j;
	int		tmp;
	t_stack	*stack;

	stack = model->sorted_stack;
	initialize_sorted_stack(model, stack);
	i = 0;
	while (i < stack->len)
	{
		j = 0 + i;
		while (j < stack->len)
		{
			if (stack->stack[j] < stack->stack[i])
			{
				tmp = stack->stack[i];
				stack->stack[i] = stack->stack[j];
				stack->stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
	stack_max_min(stack);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
