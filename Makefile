# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simao <simao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 17:27:36 by esali             #+#    #+#              #
#    Updated: 2023/05/26 12:28:43 by simao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		minishell

SRCS =		srcs/minishell.c parse/read.c

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
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re: 		fclean all