/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:14 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/17 21:30:45 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb.
*/

#include "push_swap.h"

void	ft_print_nbr(int *i)
{
	ft_putnbr_fd(*i, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char const *argv[])
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_tmp;
	t_list	*stack_next;
	char	**var_arr;
	int		temp_number;

	if (argc < 2)
		return (1);
	var_arr = (char **)ft_split(argv[1], ' ');
	i = 0;
	while (var_arr[i])
	{
		temp_number = ft_atoi(var_arr[i]);
		stack_tmp = ft_lstnew(&temp_number);
		if (i == 0)
		{
			stack_a = stack_tmp;
			stack_next = stack_tmp;
		}
		else
		{
			stack_next->next = stack_tmp;
			stack_next = stack_tmp;
		}
		i++;
	}
	ft_lstiter(stack_a, (void *)(ft_print_nbr));
	return (0);
}
