/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:09:04 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/18 09:53:39 by jseijo-p         ###   ########.fr       */
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
	int		**list_a;
	int		**list_b;
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

void		print_array(int **arr);
int			find_element_index(int *arr, int el);

#endif
