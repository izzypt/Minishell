/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:54:29 by simao             #+#    #+#             */
/*   Updated: 2023/07/31 18:48:04 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_sigint(int sig)
{
	if (get_data()->executing_cmd)
	{
		get_data()->exit = 127 + sig;
		printf("\n");
	}
	else
	{
		get_data()->exit = 127 + sig;
		printf("\n");
		rl_clear_visible_line();
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	handle_sigquit(int sig)
{
	/*char	*input_buffer;

	input_buffer = rl_line_buffer;
	if (input_buffer && *input_buffer)
	{
		get_data()->exit = 127 + sig;
		exit(0);
	}*/
	if (get_data()->executing_cmd)
	{
		get_data()->exit = 127 + sig;
		printf("Quit (core dumped)\n");
		exit(0);
	}
	else
	{
		get_data()->exit = 127 + sig;
		rl_clear_visible_line();
		rl_on_new_line();
		rl_redisplay();
	}
}
