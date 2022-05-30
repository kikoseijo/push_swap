/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/30 10:42:30 by jseijo-p         ###   ########.fr       */
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

int	main(int argc, char const **argv)
{
	t_model	*model;

	model = init_model();
	if (argc < 2)
		return (1);
	else if (argc == 2)
		ft_parse_into_arr((char *)argv[1], model->stack_a);
	else
		ft_parse_vars_arr(model, argc, (char **)argv);
	if (!check_params(model))
	{
		print_error(2);
	}
	pre_process_stack(model->stack_a);
	manual_sort(model);
	sort_radix(model);
	printf("%d\n", __INT_MAX__);
	if (!is_sorted_array(model->stack_a->stack, model->stack_a->len,
			ASCENDING_ORDER))
		print_error(3);
	else
		print_operations(model->operations, model->op_len);
	print_debug(model);
	free_model(model);
	return (EXIT_SUCCESS);
}

/*
** system("leaks --fullStacks push_swap");
*/
