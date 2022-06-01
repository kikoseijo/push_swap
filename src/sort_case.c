/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:23:17 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/31 23:22:06 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort_case_one(t_model *model)
{
	if (is_sorted(model->stack_b))
	{
		pa(model);
		pa(model);
		ra(model);
	}
	else
	{
		pa(model);
		ra(model);
		pa(model);
	}
}

static void	sort_case_two(t_model *model)
{
	if (is_sorted(model->stack_b))
	{
		pa(model);
		ra(model);
		pa(model);
		ra(model);
	}
	else
	{
		pa(model);
		pa(model);
		ra(model);
		ra(model);
	}
}

static void	sort_case(t_model *model)
{
	t_stack	*stack_a;
	int		*arr_b;
	char	option;

	stack_a = model->stack_a;
	arr_b = model->stack_b->stack;
	option = 0;
	option |= (arr_b[0] < stack_a->min && arr_b[1] < stack_a->min) << 0;
	option |= (arr_b[0] > stack_a->max && arr_b[1] > stack_a->max) << 1;
	option |= (is_sorted(model->stack_b)) << 2;
	if (option == 10 || option == 14)
		sort_case_one(model);
	else if (option == 16)
		sort_case_two(model);
	// else if (option == 1)
	else
		printf("option:%i\n", option);
}

void	fill_stack_back(t_model *model)
{
	if (model->stack_b->len == 2)
		sort_case(model);
	else
	{
		pa(model);
		if (!is_sorted(model->stack_a))
			ra(model);
	}
}
