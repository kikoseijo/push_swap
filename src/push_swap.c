/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/31 22:42:08 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb.
*/

#include "../inc/push_swap.h"

static void	print_debug(t_model *model)
{
	int	*sorted_stack;

	if (DEBUG_MODE)
	{
		sorted_stack = model->sorted_stack->stack;
		print_array(sorted_stack, model->sorted_stack->len, "Stack X");
		print_array(model->stack_a->stack, model->stack_a->len, "Stack A");
		print_array(model->stack_b->stack, model->stack_b->len, "Stack B");
	}
}

int	main(int argc, char **argv)
{
	int		error;
	t_model	*model;

	error = 0;
	model = init_model();
	if (argc < 2)
		return (1);
	if (!parser(model, argc, argv))
		error = 2;
	stack_max_min(model->stack_a);
	manual_sort(model);
	sort(model);
	if (!is_sorted_array(model->stack_a->stack, model->stack_a->len,
			ASCENDING_ORDER))
		error = 3;
	else
		print_operations(model->operations, model->op_len);
	if (DEBUG_MODE)
		print_debug(model);
	free_model(model);
	if (error > 0)
		print_error(error);
	return (EXIT_SUCCESS);
}

/*
** print_debug(model);
** system("leaks --fullStacks push_swap");
*/
