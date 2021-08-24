# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 14:56:27 by oavelar           #+#    #+#              #
#    Updated: 2021/08/24 18:33:55 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc -Wall -Wextra -Werror -g -fsanitize=address
RM			= rm -rf
NAME		= minishell 
INCS_DIR	= ./include/
MAIN_INC	= -I$(INCS_DIR)

LIB_DIR		= ./libft/
LIB_NAME	= $(LIB_DIR)libft.a

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

OBJS		= $(SRCS:.c=.o)

%.o			: %.c
			@$(CC) $(MAIN_INC) -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
			@make --silent -C $(LIB_DIR)
			@$(CC) -lreadline -ltermcap -L ~/.brew/opt/readline/lib \
			-I ~/.brew/opt/readline/include \
			$(OBJS) $(LIB_NAME) -L$(LIB_DIR) $(MAIN_INC) -o $(NAME)
			@echo "$(OK) $(NAME)compiled"

clean:
			@$(MAKE) clean --silent -C $(LIB_DIR)
			@$(RM) $(OBJS)
			@echo "$(RED)---- All clean! ---- $(COLOR_OFF)"

fclean		:
			@$(MAKE) fclean --silent -C $(LIB_DIR)
			@$(RM) $(NAME)
			@echo "$(RED) ---- All cleared! ---- $(COLOR_OFF)"

re			: fclean all

norme		:
			@norminette $(SRCS) $(INCS) $(LIB_DIR)

.PHONY		: all clean fclean re norme