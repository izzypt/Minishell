/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:40:33 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:14:44 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s1_help;
	unsigned char	*s2_help;

	s1_help = (unsigned char *)s1;
	s2_help = (unsigned char *)s2;
	i = 0;
	while (i < (int) n)
	{
		if (s1_help[i] != s2_help[i])
		{
			return (((unsigned char)s1_help[i] - (unsigned char)s2_help[i]));
		}
		i++;
	}
	return (0);
}
