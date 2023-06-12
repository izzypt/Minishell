# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simao <simao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 17:27:36 by esali             #+#    #+#              #
#    Updated: 2023/06/12 14:36:03 by simao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		minishell

SRCS =		srcs/minishell.c parser/read.c commands/pwd.c commands/ls.c parser/scanner.c parser/data.c

CFLAGS =	-lreadline -Wall -Wextra -Werror
RM =		rm

LIBFT =		libft/
LIBFT_A = 	libft/libft.a

all :		$(NAME)

$(NAME) :	$(SRCS) $(LIBFT_A)
			gcc $(CFLAGS) $(SRCS) -fsanitize=address -g $(LIBFT_A) -o $(NAME)

$(LIBFT_A) :
			cd $(LIBFT) && make bonus

clean:
			cd $(LIBFT) && make clean && cd ..

fclean:
			cd $(LIBFT) && make fclean && cd ..
			$(RM) $(NAME)

re: 		fclean all
