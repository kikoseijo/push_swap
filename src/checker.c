/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:53:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/31 22:56:59 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	call_operation_by_name(char *fun_name, t_model *model)
{
	if (!ft_memcmp(fun_name, "sa", 2))
		sa(model);
	else if (!ft_memcmp(fun_name, "sb", 2))
		sb(model);
	else if (!ft_memcmp(fun_name, "ss", 2))
		ss(model);
	else if (!ft_memcmp(fun_name, "pa", 2))
		pa(model);
	else if (!ft_memcmp(fun_name, "pb", 2))
		pb(model);
	else if (!ft_memcmp(fun_name, "ra", 2))
		ra(model);
	else if (!ft_memcmp(fun_name, "rb", 2))
		rb(model);
	else if (!ft_memcmp(fun_name, "rr", 2))
		rr(model);
	else if (!ft_memcmp(fun_name, "rra", 3))
		rra(model);
	else if (!ft_memcmp(fun_name, "rrb", 3))
		rrb(model);
	else if (!ft_memcmp(fun_name, "rrr", 3))
		rrr(model);
}

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

int	main(int argc, char **argv)
{
	t_model	*model;

	model = init_model();
	if (argc < 2)
		return (1);
	parser(model, argc, argv);
	process_commands(model);
	if (!is_sorted_array(model->stack_a->stack, model->stack_a->len,
			ASCENDING_ORDER))
		ft_putendl_fd("ko", STDERR_FILENO);
	else
		ft_putendl_fd("ok", STDERR_FILENO);
	free_model(model);
	return (EXIT_SUCCESS);
}
