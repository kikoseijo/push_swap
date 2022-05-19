/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:05:27 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 23:13:59 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_model	*initialize_model(void)
{
	t_model	*model;

	model = (t_model *)malloc(sizeof(t_model));
	if (!model)
		return (0);
	model->stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!model->stack_a)
		return (0);
	model->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!model->stack_b)
		return (0);
	return (model);
}