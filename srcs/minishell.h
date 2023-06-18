
#ifndef MINISHELL_H
# define MINISHELL_H

/* Built in Libraries */
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <dirent.h>

/* Custom Libraries */
# include "../libft/libft.h"

typedef struct s_list
{
	char			**token;
	char			*path;
	struct s_list	*next;
}				t_list;

/* Functions */
void	get_user_input(void);
void	cmd_pwd(void);
void	cmd_ls(void);

/* Parsing */
void	parse(char *input);
char	**split_token(char *input);
void	free_token(char **list);
int		is_special_char(char *input);
char	*remove_char(char *token, int pos);
char	*change_env(char *str, int i);
int		get_env_len_diff(char *str, int i);
char	*valid_cmd_path(char *cmd);

/* List */
t_list	*list_head(void);
t_list	*ft_lstnew(char **token, char *path);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

void	print_list();

#endif
