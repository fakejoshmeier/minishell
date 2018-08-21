/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josh <jmeier@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:47:59 by josh              #+#    #+#             */
/*   Updated: 2018/08/19 02:19:47 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	ft_error(char *str)
{
	ft_printf(RED"%s"RES, str);
	write(1, "\n", 1);
	exit(1);
}

void	cwd(t_sh *sh)
{
	int		i;

	i = -1;
	sh->cwd = NULL;
	sh->pwd = getcwd(sh->cwd, MAXPATHLEN);
	sh->sp_path = ft_strsplit(sh->pwd, '/');
	free(sh->cwd);
	while (sh->sp_path[++i] != NULL)
		sh->cwd = sh->sp_path[i];
	ft_printf(YEL"★  "MAG B"%s "RES BLU"jo.sh "GRE B"$>"RES, sh->cwd);
}

int		main(int ac, char *av[], char **envp)
{
	t_sh	sh;
//	void	**blt;

	(void)ac;
	(void)av;
	ft_bzero(&sh, sizeof(t_sh));
//	if (!(blt = builtin_init()))
//		ft_error("Failed to initialize builtin functions.");
	if (!(sh.env = ft_arrdup(envp)))
		ft_error("Failed to copy environment variables.");
	
	while (1)
	{
		cwd(&sh);
		if ((sh.in = in_read()))
		{
			in_parse(&sh);
		}
		MATCH(sh.sp_path, ft_freearr(sh.sp_path));
	}
//	clean_sh(&sh);
	return (0);
}
