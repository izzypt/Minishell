/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:59:56 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/13 11:16:02 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env_error(void)
{
	ft_printf("No environment variables found.\n");
	get_data()->exit = 1;
	return ;
}

void	print_export_error(char *command)
{
	ft_printf("export: %s is not a valid identifier\n", command);
	get_data()->exit = 1;
}

void	print_dir_error(char *dir)
{
	ft_printf("%s: no such file or dir.\n", dir);
	get_data()->exit = 1;
}
