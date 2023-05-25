/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:23:51 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:39:33 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*re;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
	{
		re = (char *)malloc(sizeof(char));
		re[0] = '\0';
		return (re);
	}
	else if (ft_strlen(s + start) < len)
		re = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		re = (char *)malloc(sizeof(char) * (len + 1));
	if (re == NULL)
		return (NULL);
	while ((i < (int) len) && (s[i] != '\0'))
	{
		re[i] = s[i + start];
		i++;
	}
	re[i] = '\0';
	return (re);
}
