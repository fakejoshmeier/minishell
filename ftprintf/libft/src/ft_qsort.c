/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:03:49 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/08 16:07:27 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(void *array[], int lo, int hi,
	int (*comp)(const void *, const void *))
{
	void	*pivot;
	int		i;
	int		j;
	void	*tmp;

	pivot = array[lo + (hi - lo) / 2];
	i = lo - 1;
	j = hi + 1;
	while (1)
	{
		++i;
		while (comp(pivot, array[i]))
			++i;
		--j;
		while (comp(array[j], pivot))
			--j;
		if (i >= j)
			return (j);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

static void	sort(void *array[], int lo, int hi,
	int (*comp)(const void *, const void *))
{
	int	p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, comp);
		sort(array, lo, p, comp);
		sort(array, p + 1, hi, comp);
	}
}

void		ft_qsort(void *array[], int size,
	int (*comp)(const void *, const void *))
{
	sort(array, 0, size - 1, comp);
}

int		ft_compare_str(const void *a, const void *b)
{
	return (ft_strcmp(a, b) > 0);
}

int		ft_compare_int(const void *a, const void *b)
{
	return (*((int*)a) > *((int*)b));
}
