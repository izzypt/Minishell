/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:26:26 by esali             #+#    #+#             */
/*   Updated: 2023/06/21 15:05:12 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_special_char(char *input)
{
	if (!ft_strncmp(input, "<<", 2) || !ft_strncmp(input, ">>", 2))
		return (2);
	if (input[0] == '|' || input[0] == '<' || input[0] == '>')
		return (1);
	return (0);
}

/**
 * @brief Get the length of next token
 * seperated by the following:
 * - space
 * - single (') or double (") quotes
 * - special character (<, >, <<, >>, |)
 *
 * @return length of token
 */
int	get_token_length(char *input)
{
	int	i;

	i = 0;
	if (is_special_char(input) != 0)
		return (is_special_char(input));
	while (input[i] != ' ' && !is_special_char(&(input[i])) && input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] != '"' && input[i])
				i++;
			continue ;
		}
		else if (input[i] == 39)
		{
			i++;
			while (input[i] != 39 && input[i])
				i++;
			continue ;
		}
		i++;
	}
	return (i);
}

/*
returns the number of token = elements in token-array
*/
int	get_nr_token(char *input)
{
	size_t	i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < ft_strlen(input))
	{
		while (input[i] == ' ')
			i++;
		if (input[i])
		{
			i = i + get_token_length(&(input[i]));
			nb++;
		}
	}
	return (nb);
}

/*
checks if next element has env variable and removes quotes
returns next token element
count[0] : i
count[1] : len
*/
char	*modify_token(char *input)
{
	int		*c;
	char	*str;

	c = (int *)malloc(sizeof(int) * 3);
	c[0] = 0;
	c[1] = ft_strlen(input);
	str = ft_strdup(input);
	while (c[0] < c[1])
	{
		if (str[c[0]] == 39)
			str = remove_quotes(str, c, 39);
		if (str[c[0]] == '$')
			str = manage_env(str, c);
		if (str[c[0]] == '"')
			str = manage_double_quotes(str, c);
		c[0]++;
	}
	free(c);
	free(input);
	return (str);
}

void	fill_token(char **token, int length, char *input)
{
	int	i;
	int	iterator;
	int	token_length;

	i = 0;
	iterator = 0;
	while (iterator < length)
	{
		while (input[i] == ' ')
			i++;
		token_length = get_token_length(&input[i]);
		token[iterator] = modify_token(ft_substr(input, i, token_length));
		i = i + token_length;
		iterator++;
	}
	token[iterator] = NULL;
}
