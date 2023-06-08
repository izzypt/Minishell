/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/06/07 21:57:15 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

t_data	*data_struct(void)
{
	static t_data	data;

	return (&data);
}

// void	free_data()
// {
// 	t_data	*data;
// 	char	**token;

// 	data = data_struct();
// 	token = data->token;
// 	while(token)
// 	{
// 		free(*token);
// 		token++;
// 	}
// 	free(token);
// }

void print_data()
{
	t_data	*data;
	char	**token;
	int		i;

	data = data_struct();
	token = data->token;
	i = 0;
	while(token[i] != NULL)
	{
		ft_printf("%i. %s\n", i, token[i]);
		i++;
	}
}
