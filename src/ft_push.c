/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 13:31:51 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_arr_to_arr(int *arr1, int *arr2)
{
	int	i;
	int	arr1_len;
	int	arr2_len;
	int	tmp;

	i = 0;
	arr1_len = sizeof(*arr1) / sizeof(arr1[0]);
	if (arr1_len < 1)
		return ;
	while (i < arr1_len)
	{
		if (i == 0)
			tmp = arr1[i];
		else
			arr1[i - 1] = arr1[i];
	}
	free(arr1[arr1_len - 1]);
	arr2_len = sizeof(*arr2) / sizeof(arr2[0]);
	while (arr2_len > 0)
	{
		arr2[arr2_len] = arr2[arr2_len - 1];
		arr2_len--;
	}
	arr2[0] = tmp;
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
