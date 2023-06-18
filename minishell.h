
#ifndef MINISHELL_H
# define MINISHELL_H

/* Built in Libraries */

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <dirent.h>
# include <signal.h>

/* Custom Libraries */
# include "libft/libft.h"

# define CTRL_D NULL

typedef struct s_data
{
	char	*path;
	char	*base_cmd;
	char	*full_cmd;
	char	**token;
	char	**env_var;
}				t_data;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*nxt;
}	t_env;

/* Builtin Commands */

void	cmd_cd(char *path);
void	cmd_pwd(void);
void	cmd_echo(char *line);
void	cmd_env(void);
void	cmd_export(char *variable);
void	cmd_unset(char *variable);
void	cmd_exit(void);

/* Parsing */

void	create_env(char **env);
void	get_user_input(void);
void	parse(char *input);
void	replace_env_var(char *key, char *value);

/* Struct Getters */

t_data	*data(void);
t_env	*get_env(void);

/* Memory Management */

void	free_data(void);
void	free_keys(char **keys);

/* Signal Handlers */

void	handle_sigint(int sig);
void	handle_sigquit(int sig);

#endif
