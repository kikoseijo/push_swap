/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:01:41 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 21:24:06 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	insert_first_element(int *arr, int el)
{
	int	i;
	int	len;
	int	*res;

	len = sizeof(*arr) / sizeof(arr[0]) + 1;
	res = (int *)malloc((len) * sizeof(*res));
	res[0] = el;
	i = 1;
	while (i < len)
	{
		res[i] = arr[i - 1];
		i++;
	}
	free(arr);
	arr = res;
}

static void	push_arr_to_arr(int *arr1, int *arr2)
{
	int	i;
	int	arr1_len;

	i = 0;
	arr1_len = sizeof(*arr1) / sizeof(arr1[0]);
	if (arr1_len < 1)
		return ;
	insert_first_element(arr2, arr1[0]);
	while (i < arr1_len - 1)
	{
		arr1[i] = arr1[i + 1];
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
	push_arr_to_arr(model->stack_b->stack, model->stack_a->stack);
}

/*
** pb (push b): Take the first element at the top of a
** and put it at the top of b.
** Do nothing if a is empty.
*/

void	pb(t_model *model)
{
	push_arr_to_arr(model->stack_a->stack, model->stack_b->stack);
}
