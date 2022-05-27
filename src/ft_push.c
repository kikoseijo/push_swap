/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/26 22:24:53 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	insert_first_element(t_stack *stack, int el)
{
	int	i;
	int	*res;

	stack->len++;
	res = (int *)ft_calloc((stack->len + 1), sizeof(int));
	res[0] = el;
	i = 1;
	while (i < stack->len)
	{
		res[i] = stack->stack[i - 1];
		i++;
	}
	free(stack->stack);
	stack->stack = res;
}

static void	push_arr_to_arr(t_stack *stack_1, t_stack *stack_2, t_model *model,
		const char *cmd)
{
	int	i;
	int	*res;

	i = 0;
	if (stack_1->len < 1)
		return ;
	insert_first_element(stack_2, stack_1->stack[0]);
	stack_1->len--;
	res = (int *)ft_calloc((stack_1->len + 1), sizeof(int));
	while (i < stack_1->len)
	{
		res[i] = stack_1->stack[i + 1];
		i++;
	}
	free(stack_1->stack);
	stack_1->stack = res;
	operation_push(model, cmd);
}

/*
** pa (push a): Take the first element at the top of b
** and put it at the top of a.
** Do nothing if b is empty.
*/

void	pa(t_model *model)
{
	push_arr_to_arr(model->stack_b, model->stack_a, model, __func__);
}

/*
** pb (push b): Take the first element at the top of a
** and put it at the top of b.
** Do nothing if a is empty.
*/

void	pb(t_model *model)
{
	push_arr_to_arr(model->stack_a, model->stack_b, model, __func__);
}
