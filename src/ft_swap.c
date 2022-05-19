/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:47 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 12:13:18 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap_first_two(int *arr)
{
	int	len;
	int	tmp;

	len = sizeof(*arr) / sizeof(arr[0]);
	if (len < 2)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
}

/*
** sa (swap a): Swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements.
*/

void	sa(t_model *model)
{
	swap_first_two(model->stack_a);
	printf("%s", __func__);
}

/*
** sb (swap b): Swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements.
*/

void	sb(t_model *model)
{
	swap_first_two(model->stack_b);
}

/*
** ss : sa and sb at the same time.
*/

void	ss(t_model *model)
{
	swap_first_two(model->stack_a);
	swap_first_two(model->stack_b);
}
