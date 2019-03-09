/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:04:24 by jmeier            #+#    #+#             */
/*   Updated: 2019/02/16 14:05:45 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new t_list object that gets added to the very top of the list
*/

void	*ft_lstpush(t_list **lst, void *content, size_t size)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->content = content;
	new->content_size = size;
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
	return (new);
}
