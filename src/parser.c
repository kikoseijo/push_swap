/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:57:13 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/06/12 20:46:20 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Parse string into array and checks for invalid integers
*/

static void	ft_validate_number(t_model *model, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error(model, 55);
		i++;
	}
}

static int	ft_parse_str_arr(char *str, t_stack *stack, t_model *model)
{
	int		i;
	int		nb;
	char	**var_arr;

	var_arr = (char **)ft_split(str, ' ');
	stack->len = 0;
	while (var_arr[stack->len])
	{
		ft_validate_number(model, var_arr[stack->len]);
		stack->len++;
	}
	stack->stack = (int *)malloc(stack->len * sizeof(int));
	i = 0;
	while (var_arr[i])
	{
		nb = ft_atoi(var_arr[i]);
		if ((nb == -1 || nb == 0) && ft_strlen(var_arr[i]) > 2)
		{
			stack->len = 0;
			print_error(model, 20);
		}
		stack->stack[i] = nb;
		free(var_arr[i]);
		i++;
	}
	free(var_arr);
	return (1);
}

/*
** Parse arguments into array and checks for invalid integers
*/

static int	ft_parse_argv_arr(t_model *model, int argc, char **argv)
{
	int	i;
	int	nb;

	i = 0;
	model->stack_a->stack = (int *)malloc(argc * sizeof(int));
	model->stack_a->len = 0;
	while (i < argc)
	{
		ft_validate_number(model, argv[i]);
		nb = ft_atoi(argv[i]);
		if ((nb == -1 || nb == 0) && ft_strlen(argv[i]) > 2)
		{
			model->stack_a->len = 0;
			print_error(model, 21);
		}
		model->stack_a->stack[i] = nb;
		model->stack_a->len++;
		i++;
	}
	return (1);
}

/*
** Main parser
** Parses an string or an array of arguments.
** Also checks for duplicated values after the parse.
*/

int	parser(t_model *model, int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	*stack;

	stack = model->stack_a;
	if (argc == 2)
		ft_parse_str_arr((char *)argv[1], stack, model);
	else
		ft_parse_argv_arr(model, argc - 1, argv + 1);
	i = 0;
	if (stack->len < 1)
		return (0);
	while (i < stack->len - 1)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->stack[i] == stack->stack[j])
				print_error(model, 40);
			j++;
		}
		i++;
	}
	return (1);
}
