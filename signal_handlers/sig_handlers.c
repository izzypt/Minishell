/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:54:29 by simao             #+#    #+#             */
/*   Updated: 2023/06/12 22:55:31 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	handle_sigint(int sig)
{
	sig = sig;
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

void	handle_sigquit(int sig)
{
	sig = sig;
	rl_clear_visible_line();
	rl_on_new_line();
	rl_redisplay();
}
