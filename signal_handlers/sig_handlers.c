/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:54:29 by simao             #+#    #+#             */
/*   Updated: 2023/08/08 14:45:25 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint(int sig)
{
	if (get_data()->executing_cmd)
	{
		get_data()->exit = 127 + sig;
		ft_printf("\n");
	}
	else
	{
		get_data()->exit = 127 + sig;
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

/*
\033[2K: ANSI excape sequence -> clears current line
\r: ANSI carriage return -> moves curser to beginning of the line
*/
void	handle_sigquit(int sig)
{
	if (get_data()->executing_cmd)
	{
		get_data()->exit = 127 + sig;
		ft_printf("\b \b");
		ft_printf("\b \b");
		ft_printf("Quit (core dumped)\n");
		cmd_exit(ft_itoa(get_data()->exit), 0);
	}
	else
	{
		get_data()->exit = 127 + sig;
		ft_printf("\b \b");
		ft_printf("\b \b");
	}
}
