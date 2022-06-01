/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:18:01 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/06/01 11:32:27 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Pushes a new operation into model->operations pointer of chars.
*/

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

/*
** Prints operations on standar output.
*/

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

/*
** Prints error on the standard error output
** Frees the model & exits ejecution.
*/

void	print_error(t_model *model, int err_nbr)
{
	ft_putstr_fd("Error", STDERR_FILENO);
	if (DEBUG_MODE)
	{
		ft_putstr_fd(" (", STDERR_FILENO);
		ft_putnbr_fd(err_nbr, STDERR_FILENO);
		ft_putchar_fd(')', STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	free_model(model);
	exit(err_nbr);
}
