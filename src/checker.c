/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:53:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/30 13:27:03 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	if (!is_sorted_array(model->stack_a->stack, model->stack_a->len,
			ASCENDING_ORDER))
		ft_putendl_fd("ko", STDERR_FILENO);
	else
		ft_putendl_fd("ok", STDERR_FILENO);
	free_model(model);
	return (EXIT_SUCCESS);
}
