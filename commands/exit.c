/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:31 by simao             #+#    #+#             */
/*   Updated: 2023/08/12 15:35:17 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	has_alpha(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/* changes exit number in a way,
that it is in between 0 and 256*/
int	calc_exit(int exit)
{
	if (exit == 0)
		return (0);
	else if (exit < 0)
	{
		while(exit < 0)
			exit = exit + 256;
	}
	else
	{
		while (exit > 255)
			exit = exit - 256;
	}
	return (exit);
}

/* Should release all allocated resources before exiting,
if is_cmd == 5 -> exit has more than 1 argument*/
void	cmd_exit(char *exit_nr, int is_cmd)
{
	int		number;

	if (has_alpha(exit_nr))
		number = 2;
	else
		number = ft_atoi(exit_nr);
	if (get_data()->envp)
		free_keys(get_data()->envp);
	free_env();
	if (is_cmd)
		ft_printf("exit\n");
	if (has_alpha(exit_nr))
		ft_printf("exit: %s: numeric argument required\n", exit_nr);
	else if (is_cmd == 5)
	{
		ft_printf("exit: too many arguments\n");
		number = 1;
	}
	free(exit_nr);
	free_parse();
	exit(calc_exit(number));
}

void	free_env(void)
{
	t_env	*lst;
	t_env	*tmp;

	lst = get_env();
	lst = lst->nxt;
	while (lst != NULL)
	{
		tmp = lst->nxt;
		free(lst->key);
		if (lst->value)
			free(lst->value);
		free(lst);
		lst = tmp;
	}
}
