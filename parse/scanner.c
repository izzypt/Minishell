/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:26:26 by esali             #+#    #+#             */
/*   Updated: 2023/06/10 15:08:03 by esali            ###   ########.fr       */
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
		else if(input[i] == 39) // check for env. variable
		{
			i++;
			while (input[i] != 39 && input[i])
				i++;
		}
		i++;
	}
	return (i);
}

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

void	parse(char *input)
{
	t_data	*data;
	char	**token;
	int		length;
	int		token_length;
	int		iterator;
	int		i;

	length = get_nr_token(input);
	data = data_struct();
	token = (char **)malloc(sizeof(char *) * (length + 1));
	if (!token)
		return ;
	i = 0;
	iterator = 0;
	while(iterator < length)
	{
		while (input[i] == ' ')
			i++;
		token_length = get_token_length(&input[i]);
		token[iterator] = ft_substr(input, i, token_length);

		// printf("%i", i);
		// printf(". %i. ", token_length);
		// printf("%s\n",token[iterator]);

		i = i + token_length;
		iterator++;
	}
	token[iterator] = NULL;
	data->token = token;
	i = 0;
	while(token[i] != NULL)
	{
		//write(1, &token[i], ft_strlen(token[i])); // accessing wrong memory?
		//ft_printf("%i: %s\n", i, token[i]); // SEGV
		printf("%i: %s\n", i, data->token[i]); // working
		i++;
	}

}
