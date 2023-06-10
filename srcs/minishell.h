
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

/* globsal variable saving tokens */
// char	**token;

typedef struct	s_data
{
	char	**token;
}				t_data;

/* Functions */
void	get_user_input(void);
void	cmd_pwd(void);
void	cmd_ls(void);

/* Parsing */
void	parse(char *input);


/* Data */
// void	free_token();
t_data *data_struct(void);
void	free_data();
//void	print_data();


#endif
