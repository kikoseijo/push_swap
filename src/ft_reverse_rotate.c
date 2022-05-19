/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:37 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 12:11:57 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate_array(int *arr)
{
	int	i;
	int	len;
	int	tmp;

	len = sizeof(*arr) / sizeof(arr[0]);
	if (len < 2)
		return ;
	len--;
	while (len > 0)
	{
		if (len + 1 == sizeof(*arr) / sizeof(arr[0]))
			tmp = arr[len];
		else
			arr[len + 1] = arr[len];
		i++;
	}
	arr[0] = tmp;
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
