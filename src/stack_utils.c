/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:11:52 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 22:26:35 by diade-so         ###   ########.fr       */
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

void	fill_stack(t_stack *s, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		append_node(s, arr[i]);
		i++;
	}
}

t_stack	*create_stack(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof (t_stack));
	if (!s)
		return (NULL);
	init_stack(s);
	return (s);
}
