/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:52:13 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/01 15:58:24 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern volatile	sig_atomic_t g_running;
extern volatile	sig_atomic_t g_clear;

void	signal_handler(int signal, void (*handler))
{
	struct sigaction	action;

	action = (struct sigaction){.sa_handler = handler, .sa_flags = 0};
	sigemptyset(&action.sa_mask);
	sigaction(signal, &action, NULL);
}

void	ignore(void)
{
	g_clear = TRUE;
}

void	quit(void)
{
	g_running = FALSE;
}