/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:47:59 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/03 16:54:41 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
