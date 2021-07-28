#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <limits.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include <signal.h>

# define MINISHELL_LOOP 1
# define ITS_ARG 4
# define ITS_RDR 3
# define NONE -1

typedef struct	s_rdr
{
	char *kind;
	char *arg;
}		t_rdr;

typedef struct	s_line_symbol
{
	char symb;
	int flag;
}		t_line_symbol;

typedef struct	s_env
{
	char *key;
	char *val;
}		t_env;

typedef struct s_com
{
	int num_args;
	int num_redir;
	char *com;
	char **args_new;
	char pipe_out;
	char pipe_in;
	t_line_symbol **args;

}		t_com;

typedef struct s_msh
{
	t_list *env;
	t_list *com;
	t_line_symbol *line;
	char *str;
	char **env_args;
	char **val_in_dir;
	int return_code;
	char token;
	int fd_0;
	int fd_1;
	int pipe_fd[2];
	int pipe_read_fd;
	int rdr_type[2];
	int rdr_fd[2];
	int rdr_fd2[2];
	int numwaits_pipe;
}		t_msh;

t_list *g_mem;


void	rl_replace_line(const char *a, int b);
void	handle_signals(int signo);
void	error_exit(char *i);
void	ft_clear_oldpwd(t_msh *msh);
void	ft_environment(t_msh *msh, char **env);
void	main_init(char **env, t_msh *msh);

#endif
/*aaaaaaaaaaaaaaaaaaaaaaaa



aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa



aaaaaaaaaaaaaaaaaaaaaaa*/

/* vhuvhjglhgkljhkjhkçjhkljhlkjhbjklhkjhkljhklhkjhlkjhkj*/