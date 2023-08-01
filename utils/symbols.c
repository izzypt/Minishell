/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:27:25 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/01 14:58:44 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_output(char *token)
{
	if (ft_strncmp(token, ">", 1) == 0)
		return (1);
	return (0);
}

int	is_input(char *token)
{
	if (ft_strncmp(token, "<", 1) == 0)
		return (1);
	return (0);
}

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

int	is_append(char *token)
{
	if (ft_strncmp(token, ">>", 1) == 0)
		return (1);
	return (0);
}

int	is_heredoc(char *token)
{
	if (ft_strncmp(token, "<<", 1) == 0)
		return (1);
	return (0);
}
