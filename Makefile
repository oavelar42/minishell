# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 21:44:00 by oavelar           #+#    #+#              #
#    Updated: 2021/06/21 21:55:06 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

INCLUDE		= ./minishell.h

SRC_DIR		= srcs/

SRC_FILES 	= main.c \

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED		= \033[1;31m
COLOR_OFF	= \033[0m

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)
	@echo "$(GREEN)Minishell already to work...$(COLOR_OFF)"

all : $(NAME)

clean :
	@$(RM) $(OBJ)
	@echo "\033[0;31m ---- all clean! ---- \033[0m"

fclean :
	@$(RM) $(NAME)
	@echo "\033[0;31m ---- all cleared! ---- \033[0m"

re : fclean all

.PHONY : all clean fclean re