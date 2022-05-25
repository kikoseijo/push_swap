/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:16:02 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/25 15:13:56 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** This function finds max and min values;
*/

void	pre_process_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (!stack->min || stack->min > stack->stack[i])
			stack->min = stack->stack[i];
		if (!stack->max || stack->max < stack->stack[i])
			stack->max = stack->stack[i];
		i++;
	}
}

static void	initialize_sorted_stack(t_model *model, t_stack *sorted_stack)
{
	int		i;
	t_stack	*stack_a;

	stack_a = model->stack_a;
	sorted_stack->stack = (int *)malloc((stack_a->len) * sizeof(int));
	i = 0;
	while (stack_a->stack[i])
	{
		sorted_stack->stack[i] = stack_a->stack[i];
		i++;
	}
	sorted_stack->len = stack_a->len;
}

/*
** Creates a sorted array to compare with final array;
*/

void	manual_sort(t_model *model)
{
	int		i;
	int		j;
	int		tmp;
	t_stack	*sorted_stack;

	sorted_stack = model->sorted_stack;
	initialize_sorted_stack(model, sorted_stack);
	i = 0;
	while (i < sorted_stack->len)
	{
		j = 0 + i;
		while (j < sorted_stack->len)
		{
			if (sorted_stack->stack[j] < sorted_stack->stack[i])
			{
				tmp = sorted_stack->stack[i];
				sorted_stack->stack[i] = sorted_stack->stack[j];
				sorted_stack->stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
