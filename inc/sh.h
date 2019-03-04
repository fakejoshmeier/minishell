/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 17:00:37 by josh              #+#    #+#             */
/*   Updated: 2019/03/04 15:02:06 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include "libft.h"
# include "ft_printf.h"
# include <termios.h>
# include <time.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/param.h>

# define RES "\033[0m"
# define B "\033[1m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYA "\033[36m"
# define WHI "\033[37m"

typedef struct	s_line
{
	uint8_t		*data;
	size_t		capacity;
	size_t		length;
	size_t		width;
}				t_line;

typedef void	(*t_fptr)(int ac, char **av, t_sh *sh);

typedef struct	s_cont
{
	char		*var;
	char		*value;
}				t_cont;

typedef struct	s_sh
{
	char			cwd[MAXPATHLEN];
	char			old[MAXPATHLEN];
	struct termios	term_settings;
	t_map			*builtin;
	t_map			*env;
	t_map			path;
}					t_sh;

int		read_line(t_line *line, t_sh *sh);

t_line	*init_line(size_t size);
void	line_resize(t_line *line, size_t size);
void	line_push(t_line *line, void *new);
void	*line_pop(t_line *line, void *item);
void	*line_get(t_line *line, size_t idx);

void	signal_handler(int signal, void (*handler));
void	ignore(void);
void	quit(void);

void	command_parse(t_line *line, t_sh *sh);
void	command_run(char *input, t_sh *sh);
void	get_av_ac(char *in, char ***av, int *ac, int len, t_sh *sh);
void	execute(char *cmd, char **av, t_sh *sh);
int		check_executable(char *exe);

void	b_echo(int ac, char **av, t_sh *sh);
void	b_cd(int ac, char **av, t_sh *sh);
void	b_env(int ac, char **av, t_sh *sh);
void	b_setenv(int ac, char **av, t_sh *sh);
void	b_unsetenv(int ac, char **av, t_sh *sh);
void	b_exit(int ac, char **av, t_sh *sh);
#endif
