/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:09:04 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/19 10:23:40 by jseijo-p         ###   ########.fr       */
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

typedef struct s_model
{
	int		*stack_a;
	int		*stack_b;
	int		max_a;
	int		min_a;
	int		max_b;
	int		min_b;
	char	**operations;
	int		next;

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

#endif
