/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:05:27 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/27 08:19:42 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_model	*init_model(void)
{
	t_model	*model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
		return (0);
	model->op_len = 0;
	model->stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!model->stack_a)
		return (0);
	model->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!model->stack_b)
		return (0);
	model->sorted_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!model->sorted_stack)
		return (0);
	return (model);
}

/*
** static void	free_operations(char **op)
** {
** 	int	i;
**
** 	i = 0;
** 	while (op[i])
** 	{
** 		free(op[i]);
** 		i++;
** 	}
** }
*/

void	free_model(t_model *model)
{
	if (model->stack_a)
	{
		if (model->stack_a->stack)
			free(model->stack_a->stack);
		free(model->stack_a);
	}
	if (model->stack_b)
	{
		if (model->stack_b->stack)
			free(model->stack_b->stack);
		free(model->stack_b);
	}
	if (model->sorted_stack)
	{
		if (model->sorted_stack->stack)
			free(model->sorted_stack->stack);
		free(model->sorted_stack);
	}
	free(model->operations);
	if (model)
		free(model);
}
