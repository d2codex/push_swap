/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:26:21 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/02 17:19:31 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (s->size < 2)
		return ;
	first = s->head;
	second = s->head->next;
	if (s->size == 2)
	{
		s->head = second;
		s->tail = first;
		first->next = second;
		first->prev = second;
		second->next = first;
		second->prev = first;
		return ;
	}
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = s->tail;
	first->next->prev = first;
	s->tail->next = second;
	s->head = second;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
