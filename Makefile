  # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 17:27:36 by esali             #+#    #+#              #
#    Updated: 2023/08/08 14:12:47 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		minishell

SRCS =		minishell.c parse/lexical.c parse/path.c parse/quotes.c parse/read.c \
			parse/scanner_split.c parse/scanner.c parse/syntax.c parse/var_expansion.c \
			commands/cd.c commands/echo.c commands/env.c commands/exit.c commands/export.c \
			commands/pwd.c commands/unset.c signal_handlers/sig_handlers.c utils/data.c \
			utils/free_parse.c utils/ft_join.c utils/getters.c utils/list_functions.c \
			utils/list_to_array.c utils/replace_env_var.c executor/execute.c executor/heredoc.c \
			executor/heredoc_util.c executor/pipes.c executor/redirections.c utils/symbols.c \
			utils/duplicates_std.c utils/error_handling.c utils/export_utils.c utils/fd_helpers.c \
			executor/command_chain.c parse/change_order.c executor/input.c executor/input_utils.c  \
			parse/add_token.c utils/maxlen.c

CFLAGS =	-Wall -Wextra -Werror -fsanitize=address -g

RM =		rm

LIBFT =		libft/
LIBFT_A = 	libft/libft.a

all :		$(NAME)

$(NAME) :	$(SRCS) $(LIBFT_A)
			gcc $(CFLAGS) $(SRCS) -g $(LIBFT_A) -lreadline -o $(NAME)

$(LIBFT_A) :
			cd $(LIBFT) && make

clean:
			cd $(LIBFT) && make clean && cd ..

fclean:
			cd $(LIBFT) && make fclean && cd ..
			$(RM) $(NAME)

valgrind_supp: all
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp --log-file=valgrind-out.txt ./$(NAME)

re: 		fclean all
