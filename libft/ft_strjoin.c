/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:08:57 by esali             #+#    #+#             */
/*   Updated: 2022/06/07 14:09:22 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	re = (char *) malloc((len + 1) * sizeof(char));
	if (re == NULL)
		return (NULL);
	ft_strlcpy(re, s1, len + 1);
	ft_strlcat(re, s2, len + 1);
	return (re);
}
