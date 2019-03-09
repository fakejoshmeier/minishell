/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:28:08 by jmeier            #+#    #+#             */
/*   Updated: 2019/02/20 23:35:21 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stack_init(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	s->top = NULL;
	s->size = 0;
	return (s);
}

void	*ft_stack_pop(t_stack *s)
{
	t_node	*tmp;
	void	*ret;

	if (!s->top)
		return (NULL);
	tmp = s->top;
	ret = tmp->content;
	s->top = tmp->next;
	free(tmp);
	tmp = NULL;
	s->size--;
	return (ret);
}

void	ft_stack_push(t_stack *s, void *content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->content = content;
	new->next = s->top;
	s->top = new;
	s->size++;
}

void	*ft_stack_peek(t_stack *s)
{
	if (!s->top)
		return (NULL);
	return (s->top->content);
}

int		ft_stack_isempty(t_stack *s)
{
	if (!s->top)
		return (1);
	return (0);
}
