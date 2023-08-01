/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:54:51 by simao             #+#    #+#             */
/*   Updated: 2023/08/01 19:30:42 by esali            ###   ########.fr       */
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
	if (src->value)
		new_list->value = strdup(src->value);
	else
		new_list->value = NULL;
	new_list->nxt = duplicate_list(src->nxt);
	return (new_list);
}

void	print_sorted_env(t_env	*sorted_temp)
{
	while (sorted_temp)
	{
		if (sorted_temp->value)
			printf("declare -x %s=%s\n", sorted_temp->key, sorted_temp->value);
		else
			printf("declare -x %s\n", sorted_temp->key);
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
		if (to_free->value)
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
        if (sorted_env == NULL || ft_strncmp(duplicate_env->key, sorted_env->key, ft_strlen(sorted_env->key)) < 0)
		{
			duplicate_env->nxt = sorted_env;
			sorted_env = duplicate_env;
		}
		else
		{
			temp = sorted_env;
			while (temp->nxt != NULL && ft_strncmp(duplicate_env->key, temp->nxt->key, ft_strlen(sorted_env->key)) >= 0)
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
	key_value = ft_split(variable[1], '=');
	if (replace_env_var(key_value[0], key_value[1]))
	{
		free_keys(key_value);
		return ;
	}
	while (lst->nxt != NULL)
		lst = lst->nxt;
	lst->nxt = malloc(sizeof(t_env));
	lst = lst->nxt;
	lst->key = ft_strdup(key_value[0]);
	if (key_value[1] == NULL)
		lst->value = NULL;
	else
		lst->value = ft_strdup(key_value[1]);
	lst->nxt = NULL;
	free_keys(key_value);
}
