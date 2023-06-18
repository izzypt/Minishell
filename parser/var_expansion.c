/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:00:40 by esali             #+#    #+#             */
/*   Updated: 2023/06/18 15:30:34 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* removes char in position pos from the string */
char	*remove_char(char *token, int pos)
{
	char	*substr;
	if (pos == 0)
	{
		substr = ft_substr(token, 1, ft_strlen(token));
		free(token);
		return (substr);
	}
	substr = ft_strjoin(ft_substr(token, 0, pos), ft_substr(token, pos + 1, ft_strlen(token)));
	free(token);
	return (substr);
}

/**
 returns difference in env var to value saved inside
 @TODO: Take care of numbres after alpha, ex. $hal123 OR $1hallo
 */
int	get_env_len_diff(char *str, int i)
{
	int	env_len;
	int	val_len;

	if (ft_strncmp(&str[i], "$?", 2) == 0)
		return (0);
	env_len = 1;
	while (str[i + env_len] && ft_isalpha(str[i + env_len]))
		env_len++;
	val_len = ft_strlen(getenv(ft_substr(str, i + 1, env_len)));
	return (val_len - env_len);
}

/* changes string in a way, that it exchanges the $... for the saved value*/
char	*change_env(char *input, int i)
{
	char	*str;
	char	*env_val;
	int 	env_len;

	if (ft_strncmp(&input[i], "$?", 2) == 0)
		return (input);
	env_len = 1;
	while (input[i + env_len] && ft_isalpha(input[i + env_len]))
		env_len++;
	env_val = getenv(ft_substr(input, i + 1, env_len));
	if (i == 0)
		str = env_val;
	else
		str = ft_strjoin(ft_substr(str, 0, i), env_val);
	if (input[i + env_len] != '\0')
		str = ft_strjoin(str, ft_substr(input, i + env_len, ft_strlen(input)));
	free(input);
	return (str);
}

