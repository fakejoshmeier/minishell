/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 21:40:58 by jmeier            #+#    #+#             */
/*   Updated: 2018/08/19 01:43:02 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		builtin_check(char *exe)
{
	MATCH(ft_strequ(exe, "echo"), return (1));
	OR(ft_strequ(exe, "cd"), return (2));
	OR(ft_strequ(exe, "setenv"), return (3));
	OR(ft_strequ(exe, "unsetenv"), return (4));
	OR(ft_strequ(exe, "env"), return (5));
	OR(ft_strequ(exe, "exit"), return (6));
	OR(ft_strequ(exe, ""), return (-1));
	return (0);
}

void	*builtin_init(void)
{
	void	**f_ptrs;

	NULL_GUARD(f_ptrs = (void **)malloc(sizeof(void *) * 6));
	f_ptrs[0] = &echo;
	f_ptrs[1] = &cd;
	f_ptrs[2] = &setenv;
	f_ptrs[3] = &unsetenv;
	f_ptrs[4] = &env;
	f_ptrs[5] = &exit;
	return (f_ptrs);
}
