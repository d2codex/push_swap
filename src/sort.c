/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:54:55 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/21 11:38:04 by diade-so         ###   ########.fr       */
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

void	sort_3_desc(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	c = s->head->value;
	b = s->head->next->value;
	a = s->tail->value;
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
	if (a->size == 4)
		sort_2(a);
	else
		sort_3(a);
	pb_to_a(b, a);
	pb_to_a(b, a);
}

int	count_push_limit(t_stack *a, int range_max)
{
	t_node	*curr;
	int	count;
	int	i;

	count = 0;
	i = 0;

	if (!a || a->size == 0)
		return (0);
	curr = a->head;
	while (i < a->size)
	{
		if (curr->value <= range_max)
			count++;
		curr = curr->next;
		i++;
	}
	return (count);
}

void	sort_partial(t_stack *a, t_stack *b)
{
	int	range_max;
	int	push_limit;
	int	i;
	t_node	*best;

	best = NULL;
	range_max = a->min + ((a->max - a->min) * 4 / 5);
//	printf("Debug: range_max: %d\n", range_max);
	push_limit = count_push_limit(a, range_max);
//	printf("Debug: push_limit = %d\n", push_limit);
//	printf("a->size %d\n", a->size);
	i = 0;
	while (i < push_limit)
	{
		best = find_best_node(a, b, range_max);
	//	printf("Debug: best node value = %d\n", best->value);
		if (!best)
			break ;
		if (best->value == a->max)
			break ;
		exec_rotation(a, b, best);
		pa_to_b(a, b);
		i++;
	}
}

void	sort_6_plus(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		sort_partial(a, b);
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4 || a->size == 5)
		sort_5(a, b);
	int pos = get_value_pos(b, b->max);
	rotate_to_pos_b(b, pos);
	while (b->size > 0)
		pb_to_a(b, a);
/*	if (is_sorted_ascending(a))
		printf("sorted\n");
	else
		printf("not sorted\n");*/
//	print_stack("a", a);
//	print_stack("b", b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4 || a->size == 5)
		sort_5(a, b);
	else
		sort_6_plus(a, b);
}
