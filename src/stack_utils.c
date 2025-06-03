/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:11:52 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/02 17:18:42 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->size = 0;
	s->min = INT_MAX;
	s->max = INT_MIN;
	s->head = NULL;
	s->tail = NULL;
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof (t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = node;
	node->prev = node;
	return (node);
}

void	append_node(t_stack *s, int value)
{
	t_node	*node;

	node = create_node(value);
	if (!node)
		return ;
	if (s->size == 0)
	{
		s->head = node;
		s->tail = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->prev = s->tail;
		node->next = s->head;
		s->tail->next = node;
		s->head->prev = node;
		s->tail = node;
	}
	if (value < s->min)
		s->min = value;
	if (value > s->max)
		s->max = value;
	s->size++;
}

int	is_sorted(t_stack *s)
{
	t_node	*current;

	if (s->size < 2)
		return (1);
	current = s->head;
	while (current->next != s->head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
