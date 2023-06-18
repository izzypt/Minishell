
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

typedef struct s_list
{
	char			**token;
	char			*path;
	struct s_list	*next;
}				t_list;

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
char	**split_token(char *input);
int		is_special_char(char *input);
char	*remove_char(char *token, int pos);
char	*change_env(char *str, int i);
int		get_env_len_diff(char *str, int i);
char	*valid_cmd_path(char *cmd);

/* Struct Getters */

t_list	*data(void);
t_env	*get_env(void);

/* Memory Management */

void	free_data(void);
void	free_keys(char **keys);
void	free_token(char **list);

/* Signal Handlers */

void	handle_sigint(int sig);
void	handle_sigquit(int sig);


/* List */

t_list	*list_head(void);
t_list	*ft_lstnew(char **token, char *path);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	print_list(void);

#endif