/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josh <jmeier@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 17:00:37 by josh              #+#    #+#             */
/*   Updated: 2018/08/10 17:05:42 by josh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include <libft.h>
# include <ftprintf.h>
# include <time.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct	s_sh
{
	char		*line;
	char		**env;
	char		**path;
}				t_sh;

#endif
