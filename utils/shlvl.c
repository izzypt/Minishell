/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:06:00 by esali             #+#    #+#             */
/*   Updated: 2023/08/12 19:49:32 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_digit(const char *s)
{
	int	i;
	int	is_minus;

	i = 0;
	is_minus = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			is_minus = 1;
		i++;
	}
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	if (is_minus)
		return (2);
	return (1);
}

/* increases shlvl by 1, sets to 0 if negativ,
and sets to one if not existing or not numeric*/
void	increase_shlvl(void)
{
	int		shlvl;
	char	*value;
	char	*key;
	char	*env;

	env = ft_getenv("SHLVL");
	if (!env)
		shlvl = 1;
	else if (is_digit(env) == 0)
		shlvl = 1;
	else if (is_digit(env) == 0)
		shlvl = 1;
	else if (is_digit(env) == 2)
		shlvl = 0;
	else
		shlvl = ft_atoi(env) + 1;
	value = ft_itoa(shlvl);
	key = ft_strdup("SHLVL");
	if (!env)
		new_env(key, value);
	else
		replace_env_var(key, value);
	free(value);
	free(key);
}
