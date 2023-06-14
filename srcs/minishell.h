
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
# include "../libft/libft.h"

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
	char			*pair;
	struct s_env	*nxt;
}	t_env;

/* Builtin Commands */

void	cmd_pwd(void);
void	cmd_echo(char *line);
void	cmd_env(void);
void	cmd_export(char *variable);
void	cmd_unset(char *variable);

/* Parsing */

void	get_user_input(void);
void	parse(char *input);
void	create_env(char **env);

/* Struct Getters */

t_data	*data(void);
t_env	*get_env(void);

/* Memory Management */

void	free_data(void);

/* Signal Handlers */

void	handle_sigint(int sig);
void	handle_sigquit(int sig);

#endif
