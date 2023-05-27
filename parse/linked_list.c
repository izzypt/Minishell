/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:09:09 by esali             #+#    #+#             */
/*   Updated: 2023/05/27 18:28:39 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"


int	get_token_length(char *s)
{
	int	i;

	i = 0;
	while (s[i] != ' ' && s[i])
		i++;
	return (i);
	// add checking for quotes here
}


int	add_new_token(char *input)
{
	char	*token;
	int		token_length;

	token_length = get_token_length(input);
	token = (char *)malloc(sizeof(char) * (token_length + 1));
	if (!token)
		return (0);
	// strdup token_length here
}

//TODO: Single and doube quotes!
//as well as variables (ex. VAR="test test")
void	parse(char *input)
{
	int		i;

	i = 0;
	while (i < (int)ft_strlen(input))
	{
		while (input[i] == ' ')
			i++;
		else
			i += add_new_token(&input[i]);
	}
}