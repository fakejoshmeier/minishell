/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:17:39 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/06 16:26:32 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strappend(char **src, char *add)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	len = (*src ? ft_strlen(*src) : 0) + (add ? ft_strlen(add) : 0);
	if ((new = ft_strnew(len)))
	{
		i = 0;
		if (src && *src)
			while ((*src)[i])
			{
				new[i] = (*src)[i];
				++i;
			}
		j = 0;
		if (add)
			while (*add)
				new[i + j++] = *add++;
		free(*src);
		*src = new;
	}
}
