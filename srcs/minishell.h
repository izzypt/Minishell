
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


typedef struct s_data
{
	char	*base_cmd;
	char	*full_cmd;
	char	*cmd_path;
	int		spec_char;
	char	**token;
	char	**env_var;
}				t_data;


/* Inbuilt Commands */

void	cmd_pwd(void);
void	cmd_ls(void);

/* Parsing */
void	get_user_input(void);
void	parse(char *input);

/* Struct Getters */

t_data	*data(void);

/* Memory Management */

void	free_data(void);

#endif
