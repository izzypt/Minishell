/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:55:27 by esali             #+#    #+#             */
/*   Updated: 2023/08/10 19:57:47 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	maxlen(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	else if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_strlen(s1));
	return (ft_strlen(s2));
}
