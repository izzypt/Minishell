/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:04:07 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:15:20 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_malloc(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{	
			flag = 1;
			i++;
		}
		while (s[i] != c && s[i])
		{
			flag = 0;
			i++;
		}
		count++;
	}
	if (flag == 1)
		count--;
	return (count);
}

static size_t	count_str(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static size_t	put_inside(char const *s, size_t start, char c, char *ret)
{
	size_t	j;

	j = 0;
	while (s[start] != c && s[start])
		ret[j++] = s[start++];
	if (j != 0)
		ret[j] = '\0';
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	start;
	size_t	i;

	if (!s)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (count_malloc(s, c) + 1));
	if (!ret)
		return (NULL);
	start = 0;
	i = 0;
	while (i < count_malloc(s, c))
	{
		while (s[start] == c)
			start++;
		ret[i] = (char *)malloc(sizeof(char) * (count_str((s + start), c) + 1));
		if (!ret[i])
			return (NULL);
		start = put_inside(s, start, c, ret[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
