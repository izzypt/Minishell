
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

/* Functions */
void	get_user_input(void);
void	cmd_pwd(void);
void	cmd_ls(void);
void	parse(char *input);

#endif
