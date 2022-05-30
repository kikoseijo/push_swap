/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:09:04 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/30 19:21:37 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <stdio.h>

/*
** TODO: delete unnecesary libraries.
*/

# include <stdio.h>

# define DEBUG_MODE 1
# define ASCENDING_ORDER 1
# define DESCENDING_ORDER 0

typedef struct s_stack
{
	int		max;
	int		max_bits;
	int		median;
	int		index;
	int		min;
	int		len;
	int		*stack;
}			t_stack;

typedef struct s_model
{
	char	**operations;
	int		op_len;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*sorted_stack;
}			t_model;

/*
** array_functions
*/

void		print_array(int *arr, int len, char *title);
int			find_element_index(int *arr, int el);
int			is_sorted_array(int *arr, int len, unsigned int order);
int			insert_element_at_index(int *arr, int el, int index);
int			delete_element(int *arr, int el);

/*
** Program specific Parser
*/

int			check_params(t_model *model);
void		ft_parse_into_lst(char *str, t_list **lst);
int			ft_parse_str_arr(char *str, t_stack *stack);
int			ft_parse_argv_arr(t_model *model, int argc, char **argv);

/*
** stack_functions
*/

void		manual_sort(t_model *model);
void		pre_process_stack(t_stack *stack);

/*
** op_functions
*/

void		print_error(int err_nbr);
void		operation_push(t_model *model, const char *el);
void		print_operations(char **operations, int len);

/*
** ALLOWED ALGORITHM MOVES
*/

/*
** SWAP
*/
void		sa(t_model *model);
void		sb(t_model *model);
void		ss(t_model *model);

/*
** PUSH
*/
void		pa(t_model *model);
void		pb(t_model *model);

/*
** ROTATE
*/
void		ra(t_model *model);
void		rb(t_model *model);
void		rr(t_model *model);
void		rra(t_model *model);
void		rrb(t_model *model);
void		rrr(t_model *model);

/*
** ALGORITH FUNCTIONS
*/

void		sort_radix(t_model *model);

/*
** helpers
*/

void		ft_print_title(char *title);

/*
** INITIALIZE & DESTROY
*/

t_model		*init_model(void);
void		free_model(t_model *model);

#endif
