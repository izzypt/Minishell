# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 17:27:36 by esali             #+#    #+#              #
#    Updated: 2023/06/17 14:23:23 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		minishell

SRCS =		srcs/minishell.c parse/read.c commands/pwd.c commands/ls.c parse/scanner_split.c \
			srcs/data.c parse/scanner.c parse/list_functions.c parse/var_expansion.c parse/path.c

CFLAGS =	-lreadline -Wall -Wextra -Werror
RM =		rm

LIBFT =		libft/
LIBFT_A = 	libft/libft.a

all :		$(NAME)

$(NAME) :	$(SRCS) $(LIBFT_A)
			gcc $(CFLAGS) $(SRCS) -fsanitize=address -g $(LIBFT_A) -o $(NAME)

$(LIBFT_A) :
			cd $(LIBFT) && make

clean:
			cd $(LIBFT) && make clean && cd ..

fclean:
			cd $(LIBFT) && make fclean && cd ..
			$(RM) $(NAME)

re: 		fclean all
