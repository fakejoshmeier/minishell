/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:40:19 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/04 11:23:47 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*newstr;
	int		len;
	int		j;

	len = ft_strlen(src);
	j = 0;
	if (!(newstr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (j < len)
		newstr[j++] = *src++;
	newstr[j] = '\0';
	return (newstr);
}
