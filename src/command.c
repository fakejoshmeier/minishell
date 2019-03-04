/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 23:20:29 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/04 15:01:17 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	command_parse(t_line *line, t_sh *sh)
{
	char	**commands;
	int		i;

	commands = ft_strsplit((char *)line->data, ';');
	i = -1;
	while (commands[++i])
	{
		command_run(commands[i], sh);
		free(commands[i]);
	}
	free(commands);
	line->length = 0;
}

void	command_run(char *input, t_sh *sh)
{
	t_fptr	b_in;
	char	**av;
	int		ac;

	ac = 1;
	get_av_ac(input, &av, &ac, ft_strlen(input), sh);
	
	if (command_is_valid(av[0]))
		command_execute(av[0], av, sh);
	else if ((b_in = ft_map_get(sh->builtin, ft_map_hash(sh->builtin, av[0]))))
		b_in(ac, av, sh);
	else
		ft_printf(BLU"jo.sh"RES": command not found: %s", av[0]);
	ft_freearr(av);
}

void	get_av_ac(char *in, char ***av, int *ac, int len, t_sh *sh)
{
	int		flag;
	int		i;
	int		j;

	i = -1;
	flag = -1;
	while (++i < len)
	{
		flag = in[i] == '"' ? flag * -1 : flag;
		if (flag == -1 && (ft_isspace(in[i]) || in[i] == '"'))
		{
			in[i] = '\0';
			++*ac;
		}
	}
	*av = (char **)ft_memalloc(sizeof(char *) * *ac);
	i = -1;
	j = -1;
	while (++i < *ac && flag == -1 && ++j < len)
		if (in[j])
		{
			(*av)[i] = in[j] == '"' ? ft_strdup(in + j + 1) : expand(in, sh);
			while (in[j])
				++j;
		}
}

int		check_executable(char *exe)
{
	struct stat	info;

	if (!ft_strcmp(dirname(exe), ".") && ft_strncmp(exe, ".", 1))
		return (0);
	if (access(exe, X_OK))
		return (0);
	stat(exe, &info);
	if (!S_ISREG(info.st_mode))
		return (0);
	return (1);
}
