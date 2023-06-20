/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:51:02 by esali             #+#    #+#             */
/*   Updated: 2023/06/20 17:13:05 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* removes char in position pos from the string */
char	*remove_char(char *token, int pos)
{
	char	*substr;
	char	*tmp1;
	char	*tmp2;

	if (pos == 0)
	{
		substr = ft_substr(token, 1, ft_strlen(token));
		free(token);
		return (substr);
	}
	tmp1 = ft_substr(token, 0, pos);
	tmp2 = ft_substr(token, pos + 1, ft_strlen(token));
	substr = ft_strjoin(tmp1, tmp2);
	free(token);
	return (substr);
}

// removes quotes (' or ") from strig and changes count array
char	*remove_quotes(char *str, int *count, char c)
{
	char	*ret;

	ret = ft_strdup(str);
	if (ret[count[0]] == c)
	{
		ret = remove_char(ret, count[0]);
		count[1]--;
		while (ret[count[0]] && ret[count[0]] != c)
			count[0]++;
		if (ret[count[0]])
		{
			ret = remove_char(ret, count[0]);
			count[1]--;
		}
	}
	free(str);
	return (ret);
}

char	*manage_double_quotes(char *str, int *c)
{
	char	*ret;

	ret = ft_strdup(str);
	ret = remove_char(ret, c[0]);
	c[1]--;
	while (ret[c[0]] && ret[c[0]] != '"')
	{
		if (ret[c[0]] == '$')
			ret = manage_env(ret, c);
		if (ret[c[0]] == '"')
			break ;
		c[0]++;
	}
	if (ret[c[0]])
	{
		ret = remove_char(ret, c[0]);
		c[1]--;
	}
	free(str);
	return (ret);
}
