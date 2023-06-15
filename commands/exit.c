/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/15 15:50:11 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

/* Should release all allocated resources before exiting */
void	cmd_exit(void)
{
	t_env	*lst;

	lst = get_env();
	lst = lst->nxt;
	while (lst != NULL)
	{
		free(lst);	
		lst = lst->nxt;
	}
	exit(0);
}
