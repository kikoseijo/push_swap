/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/20 11:29:10 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb.
*/

#include "../inc/push_swap.h"

void	ft_print_nbr(int *i)
{
	ft_putnbr_fd(*i, 1);
	ft_putchar_fd('\n', 1);
}

int	ft_parse_into_arr(char *str, t_stack *stack)
{
	int		i;
	char	**var_arr;

	var_arr = (char **)ft_split(str, ' ');
	stack->len = 0;
	while (var_arr[stack->len])
		stack->len++;
	stack->stack = (int *)malloc((stack->len + 1) * sizeof(int));
	i = 0;
	while (var_arr[i])
	{
		stack->stack[i] = ft_atoi(var_arr[i]);
		free(var_arr[i]);
		i++;
	}
	stack->stack[i] = '\0';
	free(var_arr);
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

int	main(int argc, char const *argv[])
{
	t_model	*model;

	if (argc < 2)
		return (1);
	model = init_model();
	ft_parse_into_arr((char *)argv[1], model->stack_a);
	sa(model);
	sa(model);
	print_operations(model->operations, model->op_len);
	free_model(model);
	return (0);
}

/*
** print_array(model->stack_a->stack);
** print_array(model->stack_a->stack);
*/

/*
** 	printf("%d\n", __INT_MAX__);
** 	printf("%d\n", (__INT_MAX__ * -1) - 1);
*/
