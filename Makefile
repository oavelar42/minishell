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

NAME		= minishell

CC			= gcc -Wall -Wextra -Werror
RM			= rm -rf

INCS_DIR	= ./includes/
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.h")

LIB_DIR		= ./libft/
LIB_NAME	= $(LIB_DIR)libft.h

SRCS_DIR 	= $(addprefix srcs/, \
							main.c \
							aux/aux.c \
							utils/utils.c)

OBJS		= $(SRCS:.c=.o)

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED			= \033[1;31m
CLEAR		= \033[0K\r\c
OK			= [\033[32mOK\033[0m]
COLOR_OFF	= \033[0m

%.o			: %.c
			@$(CC) $(MAIN_INC) $(LIB_NAME) -c $< -o $@
			@echo "[..] compiling $*.c\r\c"
			@echo "$(CLEAR)"

$(NAME)		: $(OBJS) $(INCS)
			@make --silent -C $(LIB_DIR)
			@$(CC) $(OBJS) -L $(LIB_DIR) $(LIB_NAME) $(MAIN_INC) -o $(NAME)
			@echo "$(OK) $(NAME) compiled"

all : $(NAME)

clean :
	@$(MAKE) clean --silent -C $(LIB_DIR)
	@$(RM) $(OBJS)
	@echo "$(RED)---- All clean! ---- $(COLOR_OFF)"

fclean :
	@$(MAKE) fclean --silent -C $(LIB_DIR)
	@$(RM) $(NAME)
	@echo "$(RED) ---- All cleared! ---- $(COLOR_OFF)"

re : fclean all

.PHONY : all clean fclean re