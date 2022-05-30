/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:18:01 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/30 11:24:26 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	operation_push(t_model *model, const char *el)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(model->op_len + 2, sizeof(char *));
	i = 0;
	while (i < model->op_len)
	{
		res[i] = model->operations[i];
		i++;
	}
	res[model->op_len] = (char *)el;
	model->op_len++;
	free(model->operations);
	model->operations = res;
}

void	print_operations(char **operations, int len)
{
	int	i;

	i = 0;
	while (i < len && *operations)
	{
		ft_putendl_fd(operations[i], 1);
		i++;
	}
	if (DEBUG_MODE)
	{
		ft_putstr_fd("Operation Count: ", 1);
		ft_putnbr_fd(i, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	print_error(int err_nbr)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(err_nbr);
}
