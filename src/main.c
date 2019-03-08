/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:47:59 by josh              #+#    #+#             */
/*   Updated: 2019/03/08 15:46:06 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

volatile	sig_atomic_t g_running = TRUE;
volatile	sig_atomic_t g_clear = FALSE;

ENVIRON;

/*
** Turns off echo and canonical mode, meaning my program must write out all my
** input and every input is read byte by byte
*/

void	enter_raw_mode(void)
{
	struct termios	raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_lflag &= ~(ECHO);
	raw.c_lflag &= ~(ICANON);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

/*
** Turning the '=' into a '/0' turns tmp->var into just the var name, which I
** use for hashing goodness.  Then adding the '=' back and shifting the
** value address, I can compare it to any new values later
** I've got 33 env variables, so making the capacity 3x larger seems like a
** good bet.
*/

void	hash_slinging_slasher(t_sh *sh)
{
	t_cont	*tmp;
	int		i;

	ft_map_init(&sh->builtin, 0, 18);
	ft_map_init(&sh->env, 0, 99);
	ft_map_set(&sh->builtin, ft_map_hash(&sh->builtin, "echo"), &b_echo);
	ft_map_set(&sh->builtin, ft_map_hash(&sh->builtin, "cd"), &b_cd);
	ft_map_set(&sh->builtin, ft_map_hash(&sh->builtin, "env"), &b_env);
	ft_map_set(&sh->builtin, ft_map_hash(&sh->builtin, "setenv"), &b_setenv);
	ft_map_set(&sh->builtin, ft_map_hash(&sh->builtin, "unsetenv"),
		&b_unsetenv);
	ft_map_set(&sh->builtin, ft_map_hash(&sh->builtin, "exit"), &b_exit);
	i = -1;
	while (environ[++i])
	{
		tmp = (t_cont *)malloc(sizeof(t_cont));
		tmp->var = ft_strdup(environ[i]);
		tmp->value = ft_strchr(tmp->var, '=');
		*(tmp->value) = '\0';
		ft_map_set(&sh->env, ft_map_hash(&sh->env, tmp->var), tmp);
		*(tmp->value)++ = '=';
	}
	ft_map_init(&sh->path, 0, 1080);
	update_path(sh);
}

void	prompt(void)
{
	char	pwd[PATH_MAX];
	char	*curr;

	if (g_clear)
	{
		g_clear = FALSE;
		write(1, "\n", 1);
	}
	getcwd(pwd, PATH_MAX);
	if (pwd[0] == '/' && ft_strlen(pwd) == 1)
		curr = "/";
	else
	{
		curr = ft_strrchr(pwd, '/');
		curr = curr ? curr + 1 : "?";
	}
	ft_printf(BLU"jo.sh "MAG B "%s "RES GRE"$ "RES, curr);
}

int		main(void)
{
	t_sh	sh;
	t_line	*line;

	tcgetattr(STDIN_FILENO, &sh.term_settings);
	enter_raw_mode();
	getcwd(sh.cwd, MAXPATHLEN);
	getcwd(sh.old, MAXPATHLEN);
	signal_handler(SIGTERM, quit);
	signal_handler(SIGQUIT, quit);
	signal_handler(SIGINT, ignore);
	hash_slinging_slasher(&sh);
	line = init_line(1);
	prompt();
	while (g_running)
	{
		if ((!read_line(line, &sh)) && !g_clear)
			continue ;
		line->length > 1 ? command_parse(line, &sh) : (line->length = 0);
		if (g_running)
			prompt();
	}
	free(line->data);
	free(line);
	cleanup(sh);
	return (0);
}
