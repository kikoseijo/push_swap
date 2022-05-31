/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:47 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/31 20:10:21 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap_first_two(t_stack *stack, t_model *model, const char *cmd)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = tmp;
	operation_push(model, cmd);
}

/*
** sa (swap a): Swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
*/

void	sa(t_model *model)
{
	swap_first_two(model->stack_a, model, __func__);
}

/*
** sb (swap b): Swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
*/

void	sb(t_model *model)
{
	swap_first_two(model->stack_b, model, __func__);
}

/*
** ss : sa and sb at the same time.
*/

void	ss(t_model *model)
{
	swap_first_two(model->stack_a, model, __func__);
	swap_first_two(model->stack_b, model, __func__);
}
