/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/06/01 12:06:29 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Main entry point.
** Initializes the model
** runs parser and checks for errors
** loads max and min from main array
** Initializes the sorted array need for radix sort.
** Prints operations if success sort
** frees memory or prints errors.
*/

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
	if (!is_sorted(model->stack_a))
		error = 3;
	else
		print_operations(model->operations, model->op_len);
	if (DEBUG_MODE)
		print_debug(model);
	if (error > 0)
		print_error(model, error);
	else
		free_model(model);
	return (EXIT_SUCCESS);
}

/*
** Memory leak checks. (Place before return)
** system("leaks --fullStacks push_swap");
*/
