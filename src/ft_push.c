/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/20 00:37:18 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	insert_first_element(t_stack *stack, int el)
{
	int	i;
	int	len;
	int	*res;

	len = stack->len + 1;
	res = (int *)malloc((len) * sizeof(*res));
	res[0] = el;
	i = 1;
	while (i < len)
	{
		res[i] = stack->stack[i - 1];
		i++;
	}
	free(stack->stack);
	stack->stack = res;
}

static void	push_arr_to_arr(t_stack *stack_1, t_stack *stack_2)
{
	int	i;

	i = 0;
	if (stack_1->len < 1)
		return ;
	insert_first_element(stack_2, stack_1->stack[0]);
	while (i < stack_1->len - 1)
	{
		stack_1->stack[i] = stack_1->stack[i + 1];
		i++;
	}
}

/*
** pa (push a): Take the first element at the top of b
** and put it at the top of a.
** Do nothing if b is empty.
*/

void	pa(t_model *model)
{
	push_arr_to_arr(model->stack_b, model->stack_a);
}

/*
** pb (push b): Take the first element at the top of a
** and put it at the top of b.
** Do nothing if a is empty.
*/

void	pb(t_model *model)
{
	push_arr_to_arr(model->stack_a, model->stack_b);
}
