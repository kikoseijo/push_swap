/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/30 19:36:53 by jseijo-p         ###   ########.fr       */
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
	else if (argc == 2)
		ft_parse_str_arr((char *)argv[1], model->stack_a);
	else
		ft_parse_argv_arr(model, argc - 1, argv + 1);
	if (!check_params(model))
		error = 2;
	pre_process_stack(model->stack_a);
	manual_sort(model);
	sort_radix(model);
	if (!is_sorted_array(model->stack_a->stack, model->stack_a->len,
			ASCENDING_ORDER))
		error = 3;
	else
		print_operations(model->operations, model->op_len);
	free_model(model);
	if (error > 0)
		print_error(error);
	return (EXIT_SUCCESS);
}

/*
** print_debug(model);
** system("leaks --fullStacks push_swap");
*/
