/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:39:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/25 17:15:05 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	get_max_bits(t_stack *stack)
{
	stack->max = stack->len - 1;
	stack->max_bits = 0;
	while ((stack->max >> stack->max_bits) != 0)
		stack->max_bits++;
	printf("stack->max_bits: %d\n", stack->max_bits);
}

void	sort_radix(t_model *model)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		j;
	int		size;
	int		index;

	stack_a = model->stack_a;
	stack_b = model->stack_b;
	size = stack_a->len;
	i = 0;
	get_max_bits(stack_a);
	while (i < stack_a->max_bits)
	{
		j = 0;
		while (j < stack_a->len)
		{
			index = find_element_index(model->sorted_stack->stack,
										stack_a->stack[j]);
			if (((index >> i) & 1) == 1)
				ra(model);
			else
				pb(model);
			j++;
		}
		// while (stack_b->len != 0)
		// 	pa(model);
		i++;
	}
}
