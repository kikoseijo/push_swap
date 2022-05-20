/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:16:02 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/20 11:16:24 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_push(t_stack *stack, int el)
{
	int	*res;
	int	i;

	res = (int *)malloc((stack->len + 1) * sizeof(*res));
	i = 0;
	while (i < stack->len)
	{
		res[i] = stack->stack[i];
	}
	res[stack->len] = el;
	stack->len++;
	free(stack->stack);
	stack->stack = res;
}
