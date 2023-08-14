/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:54:29 by simao             #+#    #+#             */
/*   Updated: 2023/08/12 19:01:37 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint(int sig)
{
	if (get_data()->executing_cmd)
	{
		if (!get_data()->mini_inception)
		{
			get_data()->exit = 127 + sig;
			ft_printf("\n");
		}
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
		if (!get_data()->mini_inception)
		{
			get_data()->exit = 127 + sig;
			ft_printf("\b \b");
			ft_printf("\b \b");
			ft_printf("Quit (core dumped)\n");
		}
	}
	else
	{
		get_data()->exit = 127 + sig;
		ft_printf("\b \b");
		ft_printf("\b \b");
	}
}

void	set_signal_flags(t_list *node)
{
	get_data()->executing_cmd = 1;
	if (!ft_strncmp("./minishell", node->token[0], 12))
		get_data()->mini_inception = 1;
}

void	unset_signal_flags(void)
{
	get_data()->executing_cmd = 0;
	get_data()->mini_inception = 0;
}
