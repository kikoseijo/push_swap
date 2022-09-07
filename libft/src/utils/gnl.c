/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:08:39 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/07/28 13:13:44 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*get_next_line(int fd)
{
	char	*s;
	char	*c;

	s = (char *)malloc(10000);
	c = s;
	while (read(fd, c, 1) > 0 && *c != '\n')
		c++;
	if (c > s)
	{
		*c = 0;
		return (s);
	}
	free(s);
	return (0);
}
