/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josh <jmeier@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:47:59 by josh              #+#    #+#             */
/*   Updated: 2018/08/17 01:43:38 by josh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	ft_error(char *str)
{
	ft_printf(RED"%s"RESET, str);
	write(1, "\n", 1);
	exit(1);
}



int		main(int ac, char **av, char **envp)
{
	t_sh	sh;

	(void)ac;
	(void)av;
	ft_bzero(&sh, sizeof(t_sh));
	if (!(sh.env = ft_arrdup(envp)))
		ft_error("Failed to copy environment variables.");
	while (1)
	{
		read
		ft_printf(PURPLE"%s "BLUE"jo.sh"GREEN BOLD" $>"RESET, cwd);
	}
	return (0);
}
