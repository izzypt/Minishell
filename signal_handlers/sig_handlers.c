/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:54:29 by simao             #+#    #+#             */
/*   Updated: 2023/07/29 18:56:41 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	handle_sigint(int sig)
{

	get_data()->exit = 127 + sig;
	printf("\n");
	//if (g_signal == 99)
	//{
		rl_clear_visible_line();
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	//}
}

void	handle_sigquit(int sig)
{
	get_data()->exit = 127 + sig;
	rl_clear_visible_line();
	rl_on_new_line();
	rl_redisplay();
}
