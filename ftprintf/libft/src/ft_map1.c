/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:38:23 by jmeier            #+#    #+#             */
/*   Updated: 2019/02/14 22:06:22 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	map_place_link(void **new, unsigned bucket_index, t_list *link)
{
	t_list			*i;

	link->next = NULL;
	if (!new[bucket_index])
	{
		new[bucket_index] = link;
		return ;
	}
	i = new[bucket_index];
	while (i->next)
		i = i->next;
	i->next = link;
}

void	ft_map_clean(t_map *m, void (*free_fn)(void *))
{
	unsigned int	i;
	t_list			*bucket;
	t_list			*tmp;

	i = 0;
	while (i < m->capacity)
	{
		if (!(bucket = m->data[i]))
		{
			++i;
			continue ;
		}
		while (bucket)
		{
			if (free_fn)
				free_fn(bucket->content);
			tmp = bucket;
			bucket = bucket->next;
			free(tmp);
		}
		m->data[i++] = NULL;
	}
	m->count = 0;
}