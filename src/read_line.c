/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:24:37 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/06 20:10:40 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		read_line(t_line *line, t_sh *sh)
{
	char	in;

	(void)sh;
	in = '\0';
	read(STDIN_FILENO, &in, 1);
	if (in == '\n')
	{
//		g_clear = TRUE;
		line_push(line, "\0");
		//write(STDOUT_FILENO, "\n", 1);
		return (TRUE);
	}
	else if (in == '\b' && line->length) //Whatever delete is
	{
		--line->length;
		//write(STDOUT_FILENO, "\b", 1);
	}
	// else if (in == '\t')
	// 	autocomplete(line, sh);
	else if (ft_isprint(in))
	{
		line_push(line, &in);
	//	write(STDOUT_FILENO, &in, 1);
	}
	return (FALSE);
}
