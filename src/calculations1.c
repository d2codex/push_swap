/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:36:42 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/03 16:09:13 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
int	calc_rotation_cost(int pos, int size, int *dir)
{
	if (pos <= size / 2)
	{
		*dir = 1;
		return (pos);
	}
	else
	{
		*dir = -1;
		return (size - pos);
	}
}

void	apply_node_costs(t_node *node, int pos, t_stack *a, t_stack *b)
{
	int	insert_pos;
	int	cost_b;
	int	cost_a;
	int	dir_a;
	int	dir_b;

	insert_pos = get_insert_pos_b(b, node->value);
	cost_a = calc_rotation_cost(pos, a->size, &dir_a);
	cost_b = calc_rotation_cost(insert_pos, b->size, &dir_b);
	node->cost_a = cost_a;
	node->cost_b = cost_b;
	node->dir_a = dir_a;
	node->dir_b = dir_b;
	if (dir_a == dir_b)
	{
		if (cost_a > cost_b)
			node->total_cost = cost_a;
		else
			node->total_cost = cost_b;
	}
	else
		node->total_cost = cost_a + cost_b;
}

t_node	*find_best_node(t_stack *a, t_stack *b, int range_max)
{
	t_node	*curr;
	t_node	*best;
	int	best_cost;
	int	pos;

	curr = a->head;
	best = NULL;
	best_cost = INT_MAX;
	pos = 0;
	while (pos < a->size)
	{
		apply_node_costs(curr, pos, a, b);
		if (curr->value <= range_max)
		{
			if (curr->total_cost < best_cost)
			{
				best = curr;
				best_cost = curr->total_cost;
			}
		}
		curr = curr->next;
		pos++;
	}
	return (best);
}
