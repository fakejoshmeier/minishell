/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:53:06 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/07 12:56:15 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Hashmap functions
*/

void	ft_map_init(t_map *map, unsigned int key_size, unsigned int size)
{
	map->data = ft_memalloc(sizeof(t_list) * size);
	map->count = 0;
	map->capacity = size;
	map->key_size = key_size;
}

/*
** Remember to hash the key!
*/

void	*ft_map_get(t_map *m, uint32_t hash)
{
	t_list			*bucket;

	bucket = m->data[hash % m->capacity];
	while (bucket)
	{
		if (bucket->content_size == hash)
			return (bucket->content);
		bucket = bucket->next;
	}
	return (NULL);
}

/*
** "If the initial capacity is greater than the maximum number of entries
** divided by the load factor (default .75), no rehash operations will ever
** occur"
** The hashed key is set as the content_size field, allowing reuse of t_list
** and all associated functions.
** Remember to hash the key!
*/

void	ft_map_set(t_map *m, uint32_t hash, void *ptr)
{
	t_list			*bucket;
	unsigned int	bucket_index;

	bucket_index = hash % m->capacity;
	if (!m->data[bucket_index])
	{
		ft_lstpush((t_list **)m->data + bucket_index, ptr, hash);
		++m->count;
	}
	else
	{
		bucket = m->data[bucket_index];
		while (bucket->next && bucket->next->content_size != hash)
			bucket = bucket->next;
		if (!bucket->next)
		{
			bucket->next = ft_lstnew(NULL, 0);
			++m->count;
		}
		bucket->next->content_size = hash;
		bucket->next->content = ptr;
	}
	if (m->count / (double)m->capacity >= 0.75)
		ft_map_resize(m, m->capacity * 2 + 1);
}

/*
** Remember to hash the key!
*/

void	*ft_map_remove(t_map *m, uint32_t hash)
{
	t_list			*bucket;
	void			*value;
	t_list			*last;

	if ((bucket = m->data[hash % m->capacity]) && bucket->content_size == hash)
	{
		m->data[hash % m->capacity] = bucket->next;
		value = bucket->content;
		free(bucket);
		--m->count;
		return (value);
	}
	last = NULL;
	while (bucket && bucket->content_size != hash)
	{
		last = bucket;
		bucket = bucket->next;
	}
	if (!bucket)
		return (NULL);
	last->next = bucket->next;
	value = bucket->content;
	free(bucket);
	--m->count;
	return (value);
}

void	ft_map_resize(t_map *m, unsigned size)
{
	void			**new;
	unsigned int	i;
	t_list			*bucket;
	t_list			*tmp;

	new = ft_memalloc(sizeof(t_list*) * size);
	i = 0;
	while (i < m->capacity)
	{
		if (!(bucket = m->data[i++]))
			continue ;
		while (bucket)
		{
			tmp = bucket->next;
			map_place_link(new, bucket->content_size % size, bucket);
			bucket = tmp;
		}
	}
	free(m->data);
	m->data = new;
	m->capacity = size;
}
