/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:08:18 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 13:06:35 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_insert_pos_b(t_stack *b, int value)
{
	t_node	*curr;
	int		pos;
	int		curr_val;
	int		prev_val;

	if (b->size < 2)
		return (0);
	curr = b->head;
	pos = 0;
	while (pos < b->size)
	{
		curr_val = curr->value;
		prev_val = curr->prev->value;
		if (value > curr_val && value < prev_val)
			return (pos);
		if (curr_val == b->max && value < curr_val && value < prev_val)
			return (pos);
		if(curr_val == b->max && value > curr_val && value > prev_val)
			return (pos);
		curr = curr->next;
		pos++;
	}
	write(2, "Error: No valid insert position found in B\n", 43);
	exit(1);//cannot exit here need to free first before exit
	return (0);
}

void exec_rotation(t_stack *a, t_stack *b, t_node *node)
{
	if (node->dir_a == node->dir_b)
	{
		while (node->cost_a > 0 && node->cost_b > 0)
		{
			if (node->dir_a == 1 && node->dir_b == 1) 
				rr(a, b);
			else if (node->dir_a == -1 && node->dir_b == -1) 
				rrr(a, b);
			node->cost_a--;
			node->cost_b--;
		}
	}
	do_a_rotations(a, node->cost_a, node->dir_a);
	do_b_rotations(b, node->cost_b, node->dir_b);
}

void	do_a_rotations(t_stack *a, int remaining, int dir_a)
{
	if (remaining > 0)
	{
		while (remaining--)
		{
			if (dir_a == 1)
				ra(a);
			else
				rra(a);
		}
	}
}

void	do_b_rotations(t_stack *b, int remaining, int dir_b)
{
	if (remaining > 0)
	{
		while (remaining--)
		{
			if (dir_b == 1)
				rb(b);
			else
				rrb(b);
		}
	}
}				
