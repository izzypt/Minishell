/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:53:07 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:14:42 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (char *) dst;
	s = (char *) src;
	i = 0;
	while (i != (int) n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
