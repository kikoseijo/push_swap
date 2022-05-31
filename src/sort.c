/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:39:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/31 09:43:43 by jseijo-p         ###   ########.fr       */
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
** function find_element_index gives back the index on a sorted array.
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
		while (j < size)
		{
			index = find_element_index(sorted_arr, model->stack_a->stack[0]);
			if (((index >> i) & 1) == 1)
				ra(model);
			else
				pb(model);
			j++;
		}
		while (model->stack_b->len != 0)
			pa(model);
		i++;
		printf("i:%d j:%d\n", i, j);
	}
}

static void	sort_five(t_model *model)
{
	if (model->stack_a->len > 5)
		return ;
}
static void	sort_three(t_model *model)
{
	if (model->stack_a->len > 3)
		return ;
}

void	sort(t_model *model)
{
	t_stack	*stack;

	stack = model->stack_a;
	if (stack->len > 5)
		sort_radix(model);
	else if (stack->len > 3)
		sort_five(model);
	else
		sort_three(model);
}
