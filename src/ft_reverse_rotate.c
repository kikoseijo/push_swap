/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:37 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/20 00:33:12 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate_array(t_stack *stack)
{
	int	len;
	int	tmp;

	len = stack->len;
	if (len < 2)
		return ;
	len--;
	while (len > 0)
	{
		if (len + 1 == sizeof(*stack->stack) / sizeof(stack->stack[0]))
			tmp = stack->stack[len];
		else
			stack->stack[len + 1] = stack->stack[len];
		len--;
	}
	stack->stack[0] = tmp;
}

/*
** rra (reverse rotate a): Shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

void	rra(t_model *model)
{
	reverse_rotate_array(model->stack_a);
}

/*
** rrb (reverse rotate b): Shift down all elements of stack b by 1.
** The last element becomes the first one.
*/

void	rrb(t_model *model)
{
	reverse_rotate_array(model->stack_b);
}

/*
** rrr : rra and rrb at the same time.
*/

void	rrr(t_model *model)
{
	reverse_rotate_array(model->stack_a);
	reverse_rotate_array(model->stack_b);
}
