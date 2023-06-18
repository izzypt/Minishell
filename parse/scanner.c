/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:37:09 by esali             #+#    #+#             */
/*   Updated: 2023/06/18 20:38:35 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* creates new list ele */
void new_list_token(int i, int len, char **token)
{
	char	**new_token;
	int		j;
	char	*path;

	new_token = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_token)
		return ;
	j = 0;
	while (j < len)
	{
		new_token[j] = ft_strdup(token[i + j]);
		j++;
	}
	new_token[j] = NULL;
	path = valid_cmd_path(new_token[0]);
	ft_lstlast(list_heads())->next = ft_lstnew(new_token, path);
}

/* retruns length of token variable for next list element */
int	get_len(int i, char	**token)
{
	int	save_i;


	save_i = i;
	if (is_special_char(token[i]))
		return (1);
	while(token[i] && !is_special_char(token[i]))
		i++;
	return (i - save_i);
}

/*
calls function to seperate each token into own element and saves them into list object
ex. echo hello | grep hello -> 1. echo hello  2. |   3. grep hello
*/
int	parse(char *input)
{
	char	**token;
	int		i;
	int		len;

	token = split_token(input);
	if (!token)
		return (0);
	i = 0;
	while (token[i])
	{
		len = get_len(i, token);
		new_list_token(i, len, token);
		i = i + len;
	}
	free_keys(token);
	return (1);
}
