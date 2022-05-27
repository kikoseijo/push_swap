/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 07:39:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/27 17:34:33 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** print_array(stack_a->stack, stack_a->len, "A");
** print_array(model->stack_b->stack, model->stack_b->len, "b");
*/

void	sort_radix(t_model *model)
{
	int	i;
	int	j;
	int	*sorted_arr;
	int	index;
	int	size;

	sorted_arr = model->sorted_stack->stack;
	size = model->stack_a->len;
	i = 0;
	while (1 << i < size)
	{
		j = 0;
		while (j++ < size)
		{
			index = find_element_index(sorted_arr, model->stack_a->stack[0]);
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
