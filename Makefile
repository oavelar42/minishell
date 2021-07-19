# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 21:44:00 by oavelar           #+#    #+#              #
#    Updated: 2021/07/19 21:50:31 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ./minishell
NAME_MINI	= minishell

CC			= clang -Wall -Wextra -Werror
RM			= rm -rf

INCS_DIR	= includes
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.h")

SRCS_DIR 	= srcs
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.c")

OBJS		= $(SRCS:.c=.o)

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED		= \033[1;31m
CLEAR		= \033[0K\r\c
OK			= [\033[32mOK\033[0m]
COLOR_OFF	= \033[0m

%.o			: %.c
			@echo "[..] $(NAME_MINI)... compiling $*.c\r\c"
			@$(CC) $(MAIN_INC) -c $< -o $@
			@echo "$(CLEAR)"

all : $(NAME)

$(NAME)		: $(OBJS) $(OBJS_UTILS) $(INCS)
			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)
			@echo "$(OK) $(NAME_MINI) compiled"

clean :
	@$(RM) $(OBJS)
	@echo "$(RED)---- All clean! ---- $(COLOR_OFF)"

fclean :
	@$(RM) $(NAME)
	@echo "$(RED) ---- All cleared! ---- $(COLOR_OFF)"

re : fclean all

.PHONY : all clean fclean re