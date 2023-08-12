/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:27:25 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/12 16:43:06 by esali            ###   ########.fr       */
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
