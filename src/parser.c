/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:57:13 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/30 12:02:57 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_parse_into_arr(char *str, t_stack *stack)
{
	int		i;
	int		nb;
	char	**var_arr;

	var_arr = (char **)ft_split(str, ' ');
	stack->len = 0;
	while (var_arr[stack->len])
		stack->len++;
	stack->stack = (int *)malloc(stack->len * sizeof(int));
	i = 0;
	while (var_arr[i])
	{
		nb = ft_atoi(var_arr[i]);
		if ((nb == -1 || nb == 0) && ft_strlen(var_arr[i]) > 1)
		{
			stack->len = 0;
			return (0);
		}
		stack->stack[i] = nb;
		free(var_arr[i]);
		i++;
	}
	free(var_arr);
	return (1);
}

int	ft_parse_vars_arr(t_model *model, int argc, char **argv)
{
	int	i;
	int	nb;

	i = 1;
	model->stack_a->stack = (int *)malloc(argc * sizeof(int));
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if ((nb == -1 || nb == 0) && ft_strlen(argv[i]) > 1)
		{
			model->stack_a->len = 0;
			return (0);
		}
		model->stack_a->stack[i - 1] = nb;
		model->stack_a->len++;
		i++;
	}
	return (1);
}

void	ft_parse_into_lst(char *str, t_list **lst)
{
	int		i;
	t_list	*stack_tmp;
	t_list	*stack_next;
	char	**var_arr;
	int		*temp_number;

	var_arr = (char **)ft_split(str, ' ');
	i = 0;
	while (var_arr[i])
	{
		temp_number = (int *)ft_calloc(1, sizeof(int));
		*temp_number = ft_atoi(var_arr[i]);
		free(var_arr[i]);
		stack_tmp = ft_lstnew(temp_number);
		if (i == 0)
			*lst = stack_tmp;
		else if (i == 1)
			(*lst)->next = stack_tmp;
		else
			stack_next->next = stack_tmp;
		stack_next = stack_tmp;
		i++;
	}
	free(var_arr);
}

/*
** Check params for unique values (not being repited)
** Check that all are integer numbers
*/

int	check_params(t_model *model)
{
	int		i;
	int		j;
	t_stack	*stack;

	i = 0;
	stack = model->stack_a;
	if (stack->len < 1)
		return (0);
	while (i < stack->len - 1)
	{
		j = i + 1;
		while (stack->stack[j])
		{
			if (stack->stack[i] == stack->stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
