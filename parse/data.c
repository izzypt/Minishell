/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/06/10 18:06:04 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"


/* returns data struct */
t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

/* frees **token saved inside data struct */
void	free_data()
{
	int		i;

	i = 0;
	while(data()->token[i])
	{
		free(data()->token[i]);
		i++;
	}
	free(data()->token);
}
