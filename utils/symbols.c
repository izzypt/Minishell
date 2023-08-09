/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:27:25 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/09 12:25:29 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	its_output(t_list *node)
{
	if (!node || !node->token)
		return (0);
	if (!ft_strncmp(node->token[0], ">", 2))
		return (1);
	return (0);
}

int	its_input(t_list *node)
{
	if (!node || !node->token)
		return (0);
	if (!ft_strncmp(node->token[0], "<", 2))
		return (1);
	return (0);
}

/*
- This is the function used in parsing. DIfferent from "its_a_pipe"
*/
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

int	its_a_pipe(t_list *node)
{
	if (!node || !node->token)
		return (0);
	if (!ft_strncmp(node->token[0], "|", 2))
		return (1);
	return (0);
}

int	its_append(t_list *node)
{
	if (!node || !node->token)
		return (0);
	if (!ft_strncmp(node->token[0], ">>", 3))
		return (1);
	return (0);
}

int	its_heredoc(t_list *node)
{
	if (!node || !node->token)
		return (0);
	if (!ft_strncmp(node->token[0], "<<", 3))
		return (1);
	return (0);
}
