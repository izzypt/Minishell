/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:54:51 by simao             #+#    #+#             */
/*   Updated: 2023/08/01 18:06:30 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- This function is used to duplicate the original env list.
*/
t_env	*duplicate_list(t_env	*src)
{
	t_env	*new_list;

	if (src == NULL)
		return (NULL);
	new_list = (t_env *)malloc(sizeof(t_env));
	new_list->key = strdup(src->key);
	new_list->value = strdup(src->value);
	new_list->nxt = duplicate_list(src->nxt);

	return (new_list);
}

void	print_sorted_env(t_env	*sorted_temp)
{
	while (sorted_temp)
	{
		printf("%s=%s\n", sorted_temp->key, sorted_temp->value);
		sorted_temp = sorted_temp->nxt;
	}
}

void	release_sorted_env(t_env	*sorted_env)
{
	t_env	*to_free;

	while (sorted_env)
	{
		to_free = sorted_env;
		sorted_env = sorted_env->nxt;
		free(to_free->key);
		free(to_free->value);
		free(to_free);
	}
}

void	sort_alphabetically(void)
{
	t_env	*env;
	t_env	*sorted_env;
	t_env	*next;
	t_env	*temp;
	t_env	*duplicate_env;
	t_env	*sorted_temp;

	env = get_env()->nxt;
	duplicate_env = duplicate_list(env);
	sorted_env = NULL;
	if (duplicate_env == NULL) 
		print_env_error();
	while (duplicate_env)
	{
		next = duplicate_env->nxt;
        if (sorted_env == NULL || strcmp(duplicate_env->key, sorted_env->key) < 0)
		{
			duplicate_env->nxt = sorted_env;
			sorted_env = duplicate_env;
		}
		else
		{
			temp = sorted_env;
			while (temp->nxt != NULL && strcmp(duplicate_env->key, temp->nxt->key) >= 0)
			{
				temp = temp->nxt;
			}
			duplicate_env->nxt = temp->nxt;
			temp->nxt = duplicate_env;
		}
		duplicate_env = next;
	}
	sorted_temp = sorted_env;
	print_sorted_env(sorted_temp);
	release_sorted_env(sorted_env);
}

/*
- Adds a new node to the list of env variables.
*/
void	cmd_export(char **variable)
{
	char	**key_value;
	t_env	*lst;

	lst = get_env();
	if (!variable[1])
	{
		sort_alphabetically();
		return ;
	}
	if (!ft_strchr(variable[1], '='))
		return ;
	key_value = ft_split(variable[1], '=');
	if (replace_env_var(key_value[0], key_value[1]))
		return ;
	while (lst->nxt != NULL)
		lst = lst->nxt;
	lst->nxt = malloc(sizeof(t_env));
	lst = lst->nxt;
	lst->key = ft_strdup(key_value[0]);
	lst->value = ft_strdup(key_value[1]);
	lst->nxt = NULL;
	free_keys(key_value);
}
