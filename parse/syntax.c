/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:04:06 by esali             #+#    #+#             */
/*   Updated: 2023/08/12 16:43:25 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_pipe(char *token)
{
	int	len;

	if (ft_strlen(token) > 1)
		len = ft_strlen(token);
	else
		len = 1;
	if (ft_strncmp(token, "|", len) == 0)
		return (1);
	return (0);
}

// checks if token is redirection
int	is_red(char *token)
{
	if (!token)
		return (0);
	if (is_special_char(token) && !is_pipe(token))
		return (1);
	return (0);
}

int	check_following_red(char **token, int i)
{
	if (is_pipe(token[i]) && is_pipe(token[i + 1]))
	{
		ft_printf("syntax error, unexpected token'%s'\n", token[i + 1]);
		return (2);
	}
	else if (is_red(token[i]) && is_special_char(token[i + 1]))
	{
		ft_printf("syntax error, unexpected token: '%s'\n", token[i + 1]);
		return (2);
	}
	return (0);
}

int	check_unclosed_quotes(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		i = check_quote(input, 39, i);
		i = check_quote(input, '"', i);
		if (input[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_syntax(char **token, char *input)
{
	int	i;
	int	check;

	if (check_unclosed_quotes(input))
		return (1);
	if (ft_strncmp(token[0], "|", 1) == 0)
	{
		ft_printf("syntax error, unexpected token: '|'\n");
		return (2);
	}
	i = 0;
	while (token[i + 1])
	{
		check = check_following_red(token, i);
		if (check != 0)
			return (check);
		i++;
	}
	if (is_special_char(token[i]))
	{
		ft_printf("syntax error near unexpected token: 'newline'\n");
		return (258);
	}
	return (check_lexical());
}
