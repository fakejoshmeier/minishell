/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:54:17 by jmeier            #+#    #+#             */
/*   Updated: 2019/02/18 16:37:38 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Deletes the first element and returns the content
*/

void	*ft_lstpop(t_list **lst)
{
	t_list	*tmp;
	void	*content;

	content = NULL;
	if (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		content = tmp->content;
		free(tmp);
	}
	return (content);
}
