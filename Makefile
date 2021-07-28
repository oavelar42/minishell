# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 21:44:00 by oavelar           #+#    #+#              #
#    Updated: 2021/07/24 21:33:14 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

LIBFT 			=  libft/libft.a

HEADER			=  ./includes/
CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g -I $(HEADER) #-fsanitize=address

RM				=	rm -rf

SRCS 	= srcs/aux/aux.c \
		srcs/utils/utils.c \
		srcs/main.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(HEADER)
	$(CC) -lreadline -ltermcap -L ~/.brew/opt/readline/lib \
	-I ~/.brew/opt/readline/include \
	$(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT) :
		make -C ./libft

clean:
	$(RM) $(OBJS) $(NAME)

fclean: clean
	$(RM) out

re:	fclean all

.PHONY:	all clean fclean re%