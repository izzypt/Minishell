/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:59:19 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:20:12 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)(s + i));
	while (*s != '\0')
		s++;
	while (i >= 0)
	{
		if (*s == (unsigned char) c)
			return ((char *) s);
		i--;
		s--;
	}
	return (NULL);
}
