/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:47:59 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/15 15:41:27 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_ascending(t_stack *a)
{
	t_node	*curr;
	int	i;

	curr = a->head;
	i = 0;
	while (i < a->size - 1)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int	is_sorted_descending(t_stack *b)
{
	t_node	*curr;
	int	i;

	curr = b->head;
	i = 0;
	if (!curr || b->size < 2)
		return (1);
	while (i < b->size - 1)
	{
		if (curr->value < curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int	get_value_pos(t_stack *s, int value)
{
	t_node	*curr;
	int	pos;

	curr = s->head;
	pos = 0;
	while (pos < s->size)
	{
		if (curr->value == value)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (0);
}

void	rotate_to_pos_a(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos--)
			ra(a);
	}
	else
	{
		pos = a->size - pos;
		while (pos--)
			rra(a);
	}
}

void	rotate_to_pos_b(t_stack *b, int pos)
{
	if (pos <= b->size / 2)
	{
		while (pos--)
			rb(b);
	}
	else
	{
		pos = b->size - pos;
		while (pos--)
			rrb(b);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*curr;

	while (b->size > 0)
	{
		curr = b->head;
		int pos = get_insert_pos_a(a, curr->value);
		rotate_to_pos_a(a, pos);
		pb_to_a(b, a);
		curr = curr->next;
	}
}
