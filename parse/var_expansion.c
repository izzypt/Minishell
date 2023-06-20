/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:00:40 by esali             #+#    #+#             */
/*   Updated: 2023/06/20 18:08:14 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 returns difference in env var to value saved inside
 @TODO: Take care of numbres after alpha, ex. $hal123 OR $1hallo
 */
int	get_env_len_diff(char *str, int i)
{
	int		env_len;
	int		val_len;
	char	*tmp;

	if (ft_strncmp(&str[i], "$?", 2) == 0)
		return (0);
	val_len = 0;
	env_len = 1;
	while (str[i + env_len] && ft_isalpha(str[i + env_len]))
		env_len++;
	tmp = ft_substr(str, i + 1, env_len - 1);
	if (ft_getenv(tmp) != NULL)
		val_len = ft_strlen(ft_getenv(tmp));
	free(tmp);
	return (val_len - env_len);
}

char	*fill_env(char *input, char *env_val, int i, int env_len)
{
	char	*str;
	char	*tmp;

	if (i == 0 && env_val != NULL)
		str = ft_strdup(env_val);
	else if (i == 0)
		str = ft_calloc(1, sizeof(char));
	else
	{
		str = ft_substr(input, 0, i);
		if (env_val != NULL)
			str = ft_strjoin(str, env_val);
	}
	if (input[i + env_len] != '\0')
	{
		tmp = ft_substr(input, i + env_len, ft_strlen(input));
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	free(input);
	return (str);
}

/* changes string in a way, that it exchanges the $... for the saved value*/
char	*change_env(char *input, int i)
{
	char	*env_val;
	int		env_len;
	char	*tmp;

	if (ft_strncmp(&input[i], "$?", 2) == 0)
		return (input);
	env_len = 1;
	while (input[i + env_len] && ft_isalpha(input[i + env_len]))
		env_len++;
	tmp = ft_substr(input, i + 1, env_len - 1);
	env_val = ft_getenv(tmp);
	free(tmp);
	return (fill_env(input, env_val, i, env_len));
}

char	*manage_env(char *str, int *c)
{
	int		len_diff;
	char	*ret;

	ret = ft_strdup(str);
	if (str[c[0] + 1] && str[c[0] + 1] != ' ' && str[c[0] + 1] != '"')
	{
		len_diff = get_env_len_diff(ret, c[0]);
		ret = change_env(ret, c[0]);
		c[1] = c[1] + len_diff;
		if (len_diff > 0)
			c[0] = c[0] + len_diff;
	}
	free(str);
	return (ret);
}
