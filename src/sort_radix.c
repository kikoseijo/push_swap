/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:39:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/27 13:15:37 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	get_max_bits(t_stack *stack)
{
	stack->max_bits = 0;
	printf("Max:%d\n", stack->max);
	printf("Min:%d\n", stack->min);
	while ((stack->max >> stack->max_bits) != 0)
		stack->max_bits++;
	printf("stack->max_bits: %d\n", stack->max_bits);
}

void	sort_radix_b(t_model *model)
{
	int		i;
	int		j;
	t_stack	*stack_a;
	int		*sorted_arr;
	int		index;

	stack_a = model->stack_a;
	sorted_arr = model->sorted_stack->stack;
	i = 0;
	while (1 << i < stack_a->len)
	{
		j = 0;
		while (j++ < stack_a->len)
		{
			index = find_element_index(sorted_arr, stack_a->stack[0]);
			if ((index >> i) & 1)
				ra(model);
			else
				pb(model);
		}
		while (model->stack_b->len != 0)
			pa(model);
		i++;
	}
}

/*
** 		print_array(stack_a->stack, stack_a->len, "A");
** 		print_array(model->stack_b->stack, model->stack_b->len, "b");
*/

void	sort_radix(t_model *model)
{
	int		i;
	int		j;
	t_stack	*stack_a;
	int		*sorted_arr;
	int		index;

	stack_a = model->stack_a;
	sorted_arr = model->sorted_stack->stack;
	i = 0;
	get_max_bits(stack_a);
	while (i < stack_a->max_bits)
	{
		j = 0;
		while (j++ < stack_a->len)
		{
			index = find_element_index(sorted_arr, stack_a->stack[0]);
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
