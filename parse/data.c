/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/06/10 15:07:21 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"


/* returns data struct */
t_data	*data_struct(void)
{
	static t_data	data;

	return (&data);
}

/* frees **token saved inside data struct */
void	free_data()
{
	t_data	*data;
	char	**token;
	int		i;

	data = data_struct();
	token = data->token;
	i = 0;
	while(token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
}

/* Print **token, saved in struct data */
// void print_data()
// {
// 	t_data	*data;
// 	char	**token;
// 	int		i;

// 	data = data_struct();
// 	token = data->token;
// 	i = 0;
// 	while(token[i] != NULL)
// 	{
// 		ft_printf("%i. %s\n", i, token[i]);
// 		i++;
// 	}
//}

/* frees global variable token */
// void free_token()
// {
// 	int	i;

// 	i = 0;
// 	while(token[i])
// 	{
// 		free(token[i]);
// 		i++;
// 	}
// 	free(token);
// }



