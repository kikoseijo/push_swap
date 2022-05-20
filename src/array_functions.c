/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:44:04 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/20 11:15:57 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_array(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_putnbr_fd(arr[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int	find_element_index(int *arr, int el)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == el)
			return (i);
		i++;
	}
	return (-1);
}

int	insert_element_at_index(int *arr, int el, int index)
{
	int	capacity;

	capacity = (sizeof(*arr) / sizeof(arr[0]));
	if (index >= capacity)
		return (index);
	arr[index] = el;
	return (index + 1);
}

int	delete_element(int *arr, int el)
{
	int	position;

	position = find_element_index(arr, el);
	if (position == -1)
		return (-1);
	while (arr[position])
	{
		arr[position] = arr[position + 1];
		position++;
	}
	return (position + 1);
}
