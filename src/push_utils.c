/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:18:08 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/02 17:16:29 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// updates when a new node is added to that stack
void	update_min_max(t_stack *s, int value)
{
	if (s->size == 1)
	{
		s->min = value;
		s->max = value;
	}
	else
	{
		if (value < s->min)
			s->min = value;
		if (value > s->max)
			s->max = value;
	}
}

// update stack min and max when a node has been pushed from the stack
void	update_min_max_after_push(t_stack *s)
{
	int		i;
	t_node	*curr;

	if (s->size == 0)
	{
		s->min = INT_MAX;
		s->max = INT_MIN;
		return ;
	}
	else
	{
		curr = s->head;
		s->min = curr->value;
		s->max = curr->value;
		i = 0;
		while (i < s->size)
		{
			if (curr->value < s->min)
				s->min = curr->value;
			if (curr->value > s->max)
				s->max = curr->value;
			curr = curr->next;
			i++;
		}
	}
}
