/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:26:26 by esali             #+#    #+#             */
/*   Updated: 2023/06/10 19:47:24 by simao            ###   ########.fr       */
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
		return (is_special_char(input));
	while (input[i] != ' ' && !is_special_char(&(input[i])) && input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] != '"' && input[i])
				i++;
		}
		else if (input[i] == 39)
		{
			i++;
			while (input[i] != 39 && input[i])
				i++;
		}
		i++;
	}
	return (i);
}

/**
 * @brief Get the nr token in input from user
 *
 * @return number of token
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

/**
 * @brief parses the userinput from readline and saves it inside **token in data struct
 *
 * @param userinput from readline()
 */
void	parse(char *input)
{
	int		length;
	int		token_length;
	int		iterator;
	int		i;

	length = get_nr_token(input);
	data()->token = (char **)malloc(sizeof(char *) * (length + 1));
	if (!data()->token)
		return ;
	i = 0;
	iterator = 0;
	while (iterator < length)
	{
		while (input[i] == ' ')
			i++;
		token_length = get_token_length(&input[i]);
		data()->token[iterator] = ft_substr(input, i, token_length);
		i = i + token_length;
		iterator++;
	}
	data()->token[iterator] = NULL;
}
