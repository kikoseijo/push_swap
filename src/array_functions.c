/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:44:04 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/06/01 11:38:22 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Utility function to print an array into standard output
*/

void	print_array(int *arr, int len, char *title)
{
	int	i;

	ft_print_title(title);
	if (arr && len)
	{
		ft_putstr_fd("Total(len): ", 1);
		ft_putnbr_fd(len, 1);
		ft_putchar_fd('\n', 1);
	}
	i = 0;
	while (i < len)
	{
		ft_putnbr_fd(arr[i], 1);
		if (ft_memcmp(title, "Stack X", 7) == 0)
		{
			ft_putstr_fd(" i:", 1);
			ft_putnbr_fd(i, 1);
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}

/*
** Finds the index of an element inside an array
*/

int	el_index(int *arr, int len, int el)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == el)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Not tested function
*/

int	insert_element_at_index(int *arr, int el, int index)
{
	int	capacity;

	capacity = (sizeof(*arr) / sizeof(arr[0]));
	if (index >= capacity)
		return (index);
	arr[index] = el;
	return (index + 1);
}

/*
** Not tested function
*/

int	delete_element(int *arr, int len, int el)
{
	int	position;

	position = el_index(arr, len, el);
	if (position == -1)
		return (-1);
	while (arr[position])
	{
		arr[position] = arr[position + 1];
		position++;
	}
	return (position + 1);
}
