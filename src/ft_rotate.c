/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:44 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/26 21:20:29 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_array(t_stack *stack, t_model *model, const char *cmd)
{
	int	i;
	int	tmp;

	if (stack->len < 2)
		return ;
	i = 0;
	while (stack->stack[i])
	{
		if (i == 0)
			tmp = stack->stack[i];
		else
			stack->stack[i - 1] = stack->stack[i];
		i++;
	}
	stack->stack[i - 1] = tmp;
	operation_push(model, cmd);
}

/*
** ra (rotate a): Shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

void	ra(t_model *model)
{
	rotate_array(model->stack_a, model, __func__);
}

/*
** rb (rotate b): Shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

void	rb(t_model *model)
{
	rotate_array(model->stack_b, model, __func__);
}

/*
** rr : ra and rb at the same time.
*/

void	rr(t_model *model)
{
	rotate_array(model->stack_a, model, __func__);
	rotate_array(model->stack_b, model, __func__);
}
