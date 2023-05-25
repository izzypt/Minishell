/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:31:18 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:14:48 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*s_help;
	unsigned char	ch;

	if ((int) n == 0)
		return (NULL);
	ch = (unsigned char) c;
	i = 0;
	s_help = (unsigned char *) s;
	while (i < (int) n)
	{
		if (*s_help == ch)
			return ((char *) s_help);
		s_help++;
		i++;
	}
	return (NULL);
}
