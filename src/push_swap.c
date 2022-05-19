/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 10:27:00 by jseijo-p         ###   ########.fr       */
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

void	ft_parse_into_arr(char *str, int *stack)
{
	int		i;
	char	**var_arr;

	var_arr = (char **)ft_split(str, ' ');
	i = 0;
	while (var_arr[i])
	{
		stack[i] = ft_atoi(var_arr[i]);
		i++;
	}
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
}

int	main(int argc, char const *argv[])
{
	t_model	*model;

	if (argc < 2)
		return (1);
	model = (t_model *)malloc(sizeof(t_model));
	ft_parse_into_arr((char *)argv[1], model->stack_a);
	print_array(model->stack_a);
	return (0);
}
