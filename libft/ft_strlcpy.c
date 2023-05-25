/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:00:01 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:17:48 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char			*d;
	unsigned int	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	d = dst;
	i = 0;
	while (src[i] != 0 && i < (dstsize - 1))
	{
		d[i] = src[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen(src));
}
