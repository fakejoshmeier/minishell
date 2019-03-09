/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:48:04 by jmeier            #+#    #+#             */
/*   Updated: 2019/02/14 19:46:12 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** FNV-1a hash function for hashing short strings. Output is in
** uint32_t/uint64_t meaning I can just check for numeric equality rather than
** doing a whole strequ
*/

uint32_t	ft_fnv32(const uint8_t *data, size_t size)
{
	uint32_t	hash;
	size_t		i;

	hash = 2166136261;
	i = -1;
	while (++i < size)
	{
		hash ^= data[i];
		hash *= 16777619;
	}
	return (hash);
}

uint64_t	ft_fnv64(const uint8_t *data, size_t size)
{
	uint64_t	hash;
	size_t		i;

	hash = 14695981039346656037ULL;
	i = -1;
	while (++i < size)
	{
		hash ^= data[i];
		hash *= 1099511628211ULL;
	}
	return (hash);
}

uint32_t	ft_map_hash(t_map *m, const char *key)
{
	uint32_t hash;

	hash = m->key_size ? ft_fnv32((uint8_t*)key, m->key_size) :
	ft_fnv32((uint8_t*)key, ft_strlen(key));
	return (hash);
}
