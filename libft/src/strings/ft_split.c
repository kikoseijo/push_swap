/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:16:59 by jseijo-p          #+#    #+#             */
/*   Updated: 2022/05/11 10:42:29 by jseijo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array
** of strings obtained by splitting ’s’ using the
** character ’c’ as a delimiter. The array must end
** with a NULL pointer.
*/

#include "../../inc/libft.h"
#include <stdio.h>

/*
** static size_t	ft_wordcount(char *s, char c)
** {
** 	size_t	count;
** 	size_t	i;
**
** 	if (!s)
** 		return (0);
** 	if (!ft_strlen(s))
** 		return (0);
** 	i = 0;
** 	count = s[i] != c;
** 	while (s[i])
** 	{
** 		count += (s[i] == c && s[i + 1] != c && s[i + 1] != '\0');
** 		i++;
** 	}
** 	return (count);
** }
**
** static int	ft_next_worlen(char const *s, int i, char c)
** {
** 	int	count;
**
** 	count = 0;
** 	while (s[i])
** 	{
** 		if (s[i] == c || s[i] == '\0')
** 			return (count);
** 		i++;
** 		count++;
** 	}
** 	return (count);
** }
**
** char	**ft_split(char const *s, char c)
** {
** 	size_t	i;
** 	size_t	tab_index;
** 	size_t	end;
** 	char	**tab;
**
** 	tab = ft_calloc(ft_wordcount((char *)s, c) + 1, sizeof(char *));
** 	if (!tab || !s)
** 		return (NULL);
** 	i = 0;
** 	tab_index = 0;
** 	while (tab_index < ft_wordcount((char *)s, c))
** 	{
** 		while (s[i] == c)
** 			i++;
** 		end = ft_next_worlen(s, i, c);
** 		tab[tab_index] = ft_substr(s, i, end);
** 		i += end;
** 		tab_index++;
** 		i++;
** 	}
** 	return (tab);
** }
*/

static char	**get_words(char *str, unsigned int len, int word_count)
{
	char			**res;
	unsigned int	i;
	unsigned int	w;

	res = ft_calloc(word_count + 1, sizeof(char *));
	if (res == 0)
		return (0);
	i = 0;
	w = 0;
	if (str[i] != '\0')
		res[w++] = ft_strdup(&str[i]);
	i++;
	while (i < len)
	{
		if (str[i] != '\0' && str[i - 1] == '\0')
			res[w++] = ft_strdup(&str[i]);
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	len;
	unsigned int	i;
	int				word_count;
	char			*str;
	char			**res;

	len = ft_strlen(s);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	word_count = 0;
	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			str[i] = '\0';
		else if (i == 0 || str[i - 1] == '\0')
			word_count++;
		i++;
	}
	res = get_words(str, len, word_count);
	free(str);
	return (res);
}
