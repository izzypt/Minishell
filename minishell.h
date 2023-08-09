/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:16:06 by esali             #+#    #+#             */
/*   Updated: 2023/08/09 02:30:09 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

/* Custom Libraries */

# include "libft/libft.h"

/* Structs */

typedef struct s_pipe
{
	int	fd[2];
	int	stdin;
	int	stdout;
}				t_pipe;

typedef struct s_heredoc
{
	int	fd;
}				t_heredoc;

typedef struct s_list
{
	char			**token;
	char			*path;
	struct s_list	*next;
	struct s_list	*prev;
	int				is_head;
}				t_list;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*nxt;
}				t_env;

typedef struct s_data
{
	int		exit;
	char	*input;
	char	**envp;
	int		executing_cmd;
	int		pid;
	int		log_fd;
}				t_data;

/* Builtin Commands */

void		cmd_cd(char **path);
void		cmd_pwd(void);
void		cmd_echo(char **line);
void		cmd_env(char **token);
void		cmd_export(char **variable);
void		cmd_unset(char **variable);
void		cmd_exit(char *number, int is_cmd);
t_env		*sort_loop(t_env	*dup_env, t_env *sorted_env);
void		assign_value(char *key_value, t_env *lst);

/* Parsing */

void		create_env(char **env);
void		get_user_input(void);
int			parse(char *input);
int			get_nr_token(char *input);
void		fill_token(char **token, int length, char *input);
int			is_special_char(char *input);
char		*valid_cmd_path(char *cmd);
char		*remove_quotes(char *str, int *count, char c);
int			check_quote(char *input, char c, int i);
char		*manage_env(char *str, int *count);
char		*manage_double_quotes(char *str, int *c);
void		change_order(void);
void		add_first_token(void);
int			is_pipe(char *token);
char		*ft_join(char *a, char *b);
int			check_syntax(char **token, char *input);
int			check_lexical(void);
int			is_red(char *token);

/* Executing */

void		execute_input(t_list *node, char **envp);
void		execute_builtin(t_list *node);
void		command_chain(t_list *node);
void		exec_input(t_list *node, int in_fd);
void		execute_command(t_list *node);

/* Pipes and Redirections */

int			check_redirection(t_list *node);
void		write_to_pipe(t_list *node);
void		output_from_pipe(t_list *node);
void		write_to_fd(t_list *node);
void		append_to_fd(t_list *node);
void		input_from_fd(t_list *node);

/* Input Redirection */

void		exec_input(t_list *node, int in_fd);
void		input_to_terminal(t_list *node, int in_fd);
void		input_to_fd(t_list *node, int in_fd);
void		input_to_pipe(t_list *node);
void		input_to_input(t_list *cmd_node, int fd);
void		input_to_append(t_list *cmd_node, int in_fd);

/* Heredocs */

void		heredoc(t_list *cur);
void		heredoc_to_pipe(t_list *cur);
void		write_to_command(t_list *cur);
void		heredoc_to_fd(t_list *cur);
void		heredoc_to_append(t_list *cur);

/* Struct Getters */

t_list		*get_token(void);
t_env		*get_env(void);
t_data		*get_data(void);
t_pipe		*get_pipe(void);
t_heredoc	*get_hdoc(void);

/* Memory Management */

void		free_keys(char **keys);
void		free_parse(void);
void		free_list(t_list *list);

/* Signal Handlers */

void		handle_sigint(int sig);
void		handle_sigquit(int sig);

/* List */

t_list		*get_token(void);
t_list		*ft_lstnew(char **token, char *path, t_list *lst_old);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		print_lists(void);
char		*ft_getenv(char *key);
char		**list_to_array(void);

/* Utils */

int			is_builtin(t_list *node);
int			is_built_in(char *token);
int			replace_env_var(char *key, char *value);
void		redirect_stdin_to_pipe(t_list *node);
void		redirect_stdout_to_pipe(void);
void		print_env_error(void);
void		free_env(void);
int			open_file(t_list *node);

/* File Handling */

void		reset_original_std(void);

#endif
