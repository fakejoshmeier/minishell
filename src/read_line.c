/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:24:37 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/08 15:46:25 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** No tab functionality as of now, but I didn't want to write it yet
*/

int		read_line(t_line *line, t_sh *sh)
{
	char			in;

	in = '\0';
	read(STDIN_FILENO, &in, 1);
	if (in == '\n')
	{
		line_push(line, "\0");
		write(STDOUT_FILENO, "\n", 1);
		return (TRUE);
	}
	else if (in == sh->term_settings.c_cc[VERASE] && line->length)
	{
		--line->length;
		write(STDOUT_FILENO, "\b \b", 3);
	}
	else if (in == '\t')
		return (FALSE);
	else if (ft_isprint(in))
	{
		line_push(line, &in);
		write(STDOUT_FILENO, &in, 1);
	}
	return (FALSE);
}
