/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:44 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 21:24:16 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_array(int *arr)
{
	int	i;
	int	tmp;

	if (sizeof(*arr) / sizeof(arr[0]) < 2)
		return ;
	i = 0;
	while (arr[i])
	{
		if (i == 0)
			tmp = arr[i];
		else
			arr[i - 1] = arr[i];
		i++;
	}
	arr[i + 1] = tmp;
}

/*
** ra (rotate a): Shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

void	ra(t_model *model)
{
	rotate_array(model->stack_a->stack);
}

/*
** rb (rotate b): Shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

void	rb(t_model *model)
{
	rotate_array(model->stack_b->stack);
}

/*
** rr : ra and rb at the same time.
*/

void	rr(t_model *model)
{
	rotate_array(model->stack_a->stack);
	rotate_array(model->stack_b->stack);
}
