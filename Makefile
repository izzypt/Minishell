# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esali <esali@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 17:27:36 by esali             #+#    #+#              #
#    Updated: 2023/06/21 14:36:13 by esali            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		minishell

SRCS =		minishell.c parse/*.c commands/*.c signal_handlers/*.c utils/*.c executor/*.c \

CFLAGS =	-Wall -Wextra -Werror
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

re: 		fclean all
