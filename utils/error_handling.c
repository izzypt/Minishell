/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:59:56 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/10 19:46:42 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env_error(void)
{
	ft_printf("No environment variables found.\n");
	get_data()->exit = 1;
	return ;
}

void	print_export_error(char *msg)
{
	ft_printf("export: %s is not a valid identifier\n", msg);
	get_data()->exit = 1;
}
