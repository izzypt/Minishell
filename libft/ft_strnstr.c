/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:48:53 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:20:45 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ne, size_t len)
{
	unsigned int	i;
	char			*hay1;

	i = 0;
	hay1 = (char *) hay;
	if (ft_strlen(ne) == 0)
		return ((char *) hay1);
	if (len == 0)
		return (NULL);
	while (hay1[i] != 0 && i <= ((unsigned int)len - ft_strlen(ne)))
	{
		if (ft_strncmp(&hay1[i], ne, ft_strlen(ne)) == 0)
		{
			return (&hay1[i]);
		}
		i++;
	}
	return (NULL);
}
