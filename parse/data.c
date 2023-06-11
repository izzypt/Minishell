/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/06/10 19:41:53 by simao            ###   ########.fr       */
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
void	free_data(void)
{
	int		i;

	i = 0;
	while (data()->token[i])
	{
		free(data()->token[i]);
		i++;
	}
	free(data()->token);
}
