/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:54:55 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/03 19:25:11 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *s)
{
	if (s->head->value > s->tail->value)
		sa(s);
}

void	sort_3(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	a = s->head->value;
	b = s->head->next->value;
	c = s->tail->value;
	if (a < b && b < c)
		return ;
	else if (a > b && b < c && a < c)
		sa(s);
	else if (a > b && b > c)
	{
		sa(s);
		rra(s);
	}
	else if (a > b && b < c && a > c)
		ra(s);
	else if (a < b && b > c && a < c)
	{
		sa(s);
		ra(s);
	}
	else if (a < b && b > c && a > c)
		rra(s);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	pos;

	pos = get_value_pos(a, a->min);
	rotate_to_pos_a(a, pos);
	pa_to_b(a, b);
	pos = get_value_pos(a, a->min);
	rotate_to_pos_a(a, pos);
	pa_to_b(a, b);
	if (a->size == 2)
		sort_2(a);
	else
		sort_3(a);
	pb_to_a(b, a);
	pb_to_a(b, a);
}
