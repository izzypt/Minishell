/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:44:27 by esali             #+#    #+#             */
/*   Updated: 2023/08/01 20:16:34 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*sort_loop(t_env	*dup_env, t_env *sorted_env)
{
	t_env	*temp;
	t_env	*next;

	while (dup_env)
	{
		next = dup_env->nxt;
		if (sorted_env == NULL || ft_strncmp(dup_env->key, \
		sorted_env->key, ft_strlen(sorted_env->key)) < 0)
		{
			dup_env->nxt = sorted_env;
			sorted_env = dup_env;
		}
		else
		{
			temp = sorted_env;
			while (temp->nxt != NULL && ft_strncmp(dup_env->key, \
			temp->nxt->key, ft_strlen(sorted_env->key)) >= 0)
				temp = temp->nxt;
			dup_env->nxt = temp->nxt;
			temp->nxt = dup_env;
		}
		dup_env = next;
	}
	return (sorted_env);
}

void	assign_value(char *key_value, t_env *lst)
{
	if (key_value == NULL)
		lst->value = NULL;
	else
		lst->value = ft_strdup(key_value);
}