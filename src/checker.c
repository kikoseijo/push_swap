/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:53:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/06/12 20:37:21 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Executes the commands or prints error if it does not finds it.
*/

static void	call_operation_by_name(char *fun_name, t_model *model)
{
	if (!ft_memcmp(fun_name, "sa\n", 3))
		sa(model);
	else if (!ft_memcmp(fun_name, "sb\n", 3))
		sb(model);
	else if (!ft_memcmp(fun_name, "ss\n", 3))
		ss(model);
	else if (!ft_memcmp(fun_name, "pa\n", 3))
		pa(model);
	else if (!ft_memcmp(fun_name, "pb\n", 3))
		pb(model);
	else if (!ft_memcmp(fun_name, "ra\n", 3))
		ra(model);
	else if (!ft_memcmp(fun_name, "rb\n", 3))
		rb(model);
	else if (!ft_memcmp(fun_name, "rr\n", 3))
		rr(model);
	else if (!ft_memcmp(fun_name, "rra\n", 4))
		rra(model);
	else if (!ft_memcmp(fun_name, "rrb\n", 4))
		rrb(model);
	else if (!ft_memcmp(fun_name, "rrr\n", 4))
		rrr(model);
	else
		print_error(model, 8);
}

/*
** Reads from standard input
** process operations on model->stack_a
*/

static void	process_commands(t_model *model)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (ft_strchr(line, '\n'))
	{
		call_operation_by_name(line, model);
		line = get_next_line(STDIN_FILENO);
	}
	if (model->stack_a->len < 1)
		exit(4);
}

/*
** Aplication entry point
** Inits model > parses and validates inputs
** Reads and process commands from standard input
** Prints ok or ko and frees the model.
*/

int	main(int argc, char **argv)
{
	t_model	*model;

	model = init_model();
	if (argc < 2)
		return (1);
	parser(model, argc, argv);
	process_commands(model);
	if (!is_sorted(model->stack_a))
		ft_putendl_fd("KO", STDERR_FILENO);
	else
		ft_putendl_fd("OK", STDERR_FILENO);
	free_model(model);
	return (EXIT_SUCCESS);
}
