
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

typedef struct s_parser
{
	char			*token;
	struct s_parser	*next;
}	t_parser;

/* Functions */
void	get_user_input(void);
void	cmd_pwd(void);
void	cmd_ls(void);

#endif
