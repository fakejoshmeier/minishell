/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josh <jmeier@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 17:00:37 by josh              #+#    #+#             */
/*   Updated: 2018/08/19 01:59:01 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include <libft.h>
# include <ft_printf.h>
# include <time.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
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

typedef struct	s_sh
{
	char		*cwd;
	char		*pwd;
	char		**sp_path;
	char		*in;
	char		**tokens;
	char		**env;
	char		*exe;
	char		**exe_args;
}				t_sh;

char			*in_read(void);
void			in_parse(t_sh *sh);

void			*builtin_init(void);

#endif
