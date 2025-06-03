/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:59:04 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/06 01:22:48 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	t_node	*node;

	node = src->head;
//	printf("Debug: Pushing value %d from src to dst\n", node->value);
	if (src->size == 0)
		return ;
	adjust_src(src);
	adjust_dst(dst, node);
}

void	adjust_src(t_stack *src)
{
	t_node	*removed;

	if (src->size == 1)
	{
		src->head = NULL;
		src->tail = NULL;
	}
	else
	{
		removed = src->head;
		src->head = removed->next;
		src->tail->next = src->head;
		src->head->prev = src->tail;
		if (src->size == 2)
		{
			src->head->next = src->head;
			src->head->prev = src->head;
			src->tail = src->head;
		}
	}
	src->size--;
	update_min_max_after_push(src);
}

void	adjust_dst(t_stack *dst, t_node *node)
{
	if (dst->size == 0)
	{
		node->next = node;
		node->prev = node;
		dst->head = node;
		dst->tail = node;
	}
	else
	{
		node->next = dst->head;
		node->prev = dst->tail;
		dst->head->prev = node;
		dst->tail->next = node;
		dst->head = node;
	}
	dst->size++;
	update_min_max(dst, node->value);
}

void	pb_to_a(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
//	fprintf(stderr, "After pa_to_b: size_a = %d, size_b = %d\n", a->size, b->size);
}

void	pa_to_b(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
//	fprintf(stderr, "After pa_to_b: size_a = %d, size_b = %d\n", a->size, b->size);
}
