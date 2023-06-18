/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:37:09 by esali             #+#    #+#             */
/*   Updated: 2023/06/18 15:48:27 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* creates new list ele */
void new_list_token(int i, int len, char **token)
{
	char	**new_token;
	int		j;
	t_list	*print;
	char	*path;
	// t_list	*list_ele;

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

	// list_ele = list_head();
	// if (i == 0)
	// 	list_ele = ft_lstnew(new_token);
	// else
	ft_lstlast(list_heads())->next = ft_lstnew(new_token, path);

	print = ft_lstlast(list_heads());
	j = 0;
	while (print->token[j])
	{
		printf("%i. %s ", j, print->token[j]);
		j++;
	}
	printf("path: %s\n", print->path);
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
void	parse(char *input)
{
	char	**token;
	int		i;
	int		len;

	token = split_token(input);
	i = 0;
	while(token[i])
	{
		len = get_len(i, token);
		//printf("%i\n", len);
		new_list_token(i, len, token);
		i = i + len;
	}
	free_keys(token);
	//print_list();
	//free_token(token);
}
