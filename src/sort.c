/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:39:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/06/01 08:51:17 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	get_max_bits(t_stack *stack, int max)
{
	stack->max_bits = 0;
	while ((max >> stack->max_bits) != 0)
		stack->max_bits++;
}

/*
** Will use model->sorted_stack index for sorting unsigned integers
** function el_index gives back the index on a sorted array.
*/

static void	sort_radix(t_model *model)
{
	int	i;
	int	j;
	int	*sorted_arr;
	int	index;
	int	size;

	sorted_arr = model->sorted_stack->stack;
	size = model->stack_a->len;
	i = 0;
	get_max_bits(model->stack_a, size - 1);
	while (i < model->stack_a->max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			index = el_index(sorted_arr, size, model->stack_a->stack[0]);
			if (((index >> i) & 1) == 1)
				ra(model);
			else
				pb(model);
		}
		while (model->stack_b->len != 0)
			pa(model);
		i++;
	}
}

static void	sort_three(t_model *model)
{
	int	*arr;

	if (is_sorted(model->stack_a))
		return ;
	arr = model->stack_a->stack;
	if (arr[1] < arr[0] && arr[0] < arr[2])
		sa(model);
	else if (arr[1] < arr[2] && arr[2] < arr[0])
		ra(model);
	else if (arr[2] < arr[0] && arr[0] < arr[1])
		rra(model);
	else if (arr[0] < arr[2] && arr[2] < arr[1])
	{
		sa(model);
		ra(model);
	}
	else if (arr[2] < arr[1] && arr[1] < arr[0])
	{
		sa(model);
		rra(model);
	}
}

static void	sort_five(t_model *model)
{
	int	max_index;
	int	min_index;
	int	*arr;

	min_index = model->stack_a->min;
	max_index = model->stack_a->max;
	if (is_sorted(model->stack_a))
		return ;
	while (model->stack_a->len > 3)
	{
		arr = model->stack_a->stack;
		if (arr[0] == model->stack_a->min || arr[0] == model->stack_a->max)
		{
			pb(model);
			stack_max_min(model->stack_a);
		}
		else
			ra(model);
	}
	stack_max_min(model->stack_b);
	sort_three(model);
	fill_stack_back(model);
}

void	sort(t_model *model)
{
	t_stack	*stack;

	if (is_sorted(model->stack_a))
		return ;
	stack = model->stack_a;
	if (stack->len > 5)
		sort_radix(model);
	else if (stack->len > 3)
		sort_five(model);
	else
		sort_three(model);
}
