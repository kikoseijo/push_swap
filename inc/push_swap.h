/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:09:04 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/20 11:54:14 by jseijo-p         ###   ########.fr       */
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

typedef struct s_stack
{
	int		max;
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
}			t_model;

/*
** array_functions
*/

void		print_array(int *arr);
int			find_element_index(int *arr, int el);
int			insert_element_at_index(int *arr, int el, int index);
int			delete_element(int *arr, int el);

/*
** stack_functions
*/

void		stack_push(t_stack *stack, int el);
/*
** op_functions
*/

void		operation_push(t_model *model, const char *el);
void		print_operations(char *operations, int len);

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

/*
** PRINTING
*/
void		print_result(t_model *model);

/*
** INITIALIZE & DESTROY
*/

t_model		*init_model(void);
void		free_model(t_model *model);

#endif
