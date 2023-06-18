/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:26:26 by esali             #+#    #+#             */
/*   Updated: 2023/06/17 14:23:00 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

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
	 	return is_special_char(input);
	while (input[i] != ' ' && !is_special_char(&(input[i])) && input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] != '"' && input[i])
				i++;
		}
		else if(input[i] == 39)
		{
			i++;
			while (input[i] != 39 && input[i])
				i++;
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
	int	nb;

	i = 0;
	nb = 0;
	while(i < ft_strlen(input))
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
*/
char	*fill_token(char *input)
{
	int		i;
	int		len;
	int		len_diff;
	char	*str;

	i = 0;
	str = ft_strdup(input);
	len = ft_strlen(input);
	while (i < len) // look for env?
	{
		if (str[i] == 39)
		{
			str = remove_char(str, i);
			len--;
			while(str[i] && str[i] != 39)
				i++;
			if (str[i])
			{
				str = remove_char(str, i);
				len--;
			}
		}
		if (str[i] == '$' && str[i + 1])
		{
			len_diff = get_env_len_diff(str, i);
			str = change_env(str, i);
			len = len + len_diff;
			i = i + len_diff;
		}
		if (str[i] == '"')
		{
			str = remove_char(str, i);
			len--;
			while(str[i] && str[i] != '"')
			{
				if (str[i] == '$')
				{
					len_diff = get_env_len_diff(str, i);
					str = change_env(str, i);
					len = len + len_diff;
					i = i + len_diff;
				}
				i++;
			}
			if (str[i])
			{
				str = remove_char(str, i);
				len--;
			}
		}
		i++;
	}
	free(input);
	//ft_printf("%s\n", str);
	return (str);
}

/*
 parses the userinput from readline and returns it in array of strings
 */
char	**split_token(char *input)
{
	int		length;
	char	**token;
	int		token_length;
	int		iterator;
	int		i;

	length = get_nr_token(input);
	token = (char **)malloc(sizeof(char *) * (length + 1));
	if (!token)
		return NULL;
	i = 0;
	iterator = 0;
	while(iterator < length)
	{
		while (input[i] == ' ')
			i++;
		token_length = get_token_length(&input[i]);
		token[iterator] = fill_token(ft_substr(input, i, token_length));
		i = i + token_length;
		iterator++;
	}
	token[iterator] = NULL;
	return (token);
}
