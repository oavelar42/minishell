# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 14:56:27 by oavelar           #+#    #+#              #
#    Updated: 2021/08/02 15:50:38 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

RM	= rm -rf

HEADER = ./include/

LIB_DIR = ./libft/
LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra -g -I $(HEADER) #-fsanitize=address

SRCS =	srcs/main/minishell.c \
	srcs/main/command.c \
	srcs/main/execute.c \
	srcs/main/execute_utils.c \
	srcs/main/execute_utils_2.c \
	srcs/main/redir.c \
	srcs/main/redir_utils.c \
	srcs/main/redir_utils_2.c \
	srcs/main/redir_utils_3.c \
	srcs/main/pipe.c \
	srcs/parse/parser.c \
	srcs/parse/parser_utils.c \
	srcs/parse/parser_utils2.c \
	srcs/parse/parser_utils3.c \
	srcs/parse/preparser.c \
	srcs/parse/parse_env.c \
	srcs/parse/parse_env_utils.c \
	srcs/parse/parse_env_utils2.c \
	srcs/parse/env_list.c \
	srcs/parse/syntax.c \
	srcs/builtin/echo.c \
	srcs/builtin/cd.c \
	srcs/builtin/pwd.c \
	srcs/builtin/env.c \
	srcs/builtin/unset.c \
	srcs/builtin/export.c \
	srcs/builtin/export_utils.c \
	srcs/builtin/exit.c \
	srcs/builtin/builtin.c \
	srcs/utils/utils.c \
	srcs/utils/utils_2.c \
	srcs/utils/utils_3.c 

OK			= [\033[32mOK\033[0m]
RED			= \033[1;31m
OFF			= \033[0m

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
		@make --silent -C $(LIB_DIR)	
		@$(CC) -lreadline -ltermcap -L ~/.brew/opt/readline/lib \
			-I ~/.brew/opt/readline/include \
		$(OBJS) -o $(NAME) $(LIBFT)
		@echo "$(OK) $(NAME) compiled"

$(LIB_DIR) :
	make --silent -C ./libft

clean :
		@$(MAKE) clean --silent -C $(LIB_DIR)
		@$(RM) $(OBJS)
		@echo "$(RED)---- All clean! ---- $(COLOR_OFF)"

fclean :
		@$(MAKE) fclean --silent -C $(LIB_DIR)
		@$(RM) $(OBJS) $(NAME)
		@echo "$(RED) ---- All cleared! ---- $(COLOR_OFF)"

re : fclean all

norme		:
			@norminette $(SRCS) $(INCS) $(LIB_DIR)

.PHONY		: all clean fclean re norme