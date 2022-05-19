/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:09:04 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 23:13:26 by jseijo-p         ###   ########.fr       */
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
	int		*stack;
}			t_stack;

typedef struct s_model
{
	char	**operations;
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

t_model		*initialize_model(void);

#endif