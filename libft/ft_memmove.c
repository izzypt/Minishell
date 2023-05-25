/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:28:40 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:14:37 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;
	char		*lastdst;
	const char	*lastsrc;

	dst1 = dst;
	src1 = src;
	if (!dst && !src)
		return (NULL);
	if (dst1 < src1)
		while (len--)
			*dst1++ = *src1++;
	else
	{
		lastsrc = (char *)src1 + (len - 1);
		lastdst = dst1 + (len - 1);
		while (len--)
			*lastdst-- = *lastsrc--;
	}
	return (dst);
}
