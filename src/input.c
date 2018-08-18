/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:49:27 by jmeier            #+#    #+#             */
/*   Updated: 2018/08/17 20:50:34 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char	*in_read(void)
{
	char	*ret;
	char	c;
	int		i;

	ret = (char *)ft_memalloc(sizeof(char) * MAXPATHLEN);
	i = 0;
	while (read(STDIN_FILENO, &c, 1) && c != '\n')
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

void	in_parse(t_sh *sh)
{
	sh->exe = ft_strtrim(sh->in);
	sh->exe_args = ft_strsplit(sh->exe, ' ');
}
