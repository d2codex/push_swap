/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:00:29 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 19:33:53 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_table(t_hash *table, int table_size)
{
	int	i;

	i = 0;
	while (i < table_size)
	{
		table[i].seen = 0;
		i++;
	}
}

bool	check_duplicate(t_node *head, int size, int min)
{
	t_dup_check	c;

	c.table = malloc((size * 2) * sizeof (t_hash));
	if (!c.table)
		return (false);
	c.curr = head;
	init_table(c.table, size * 2);
	c.i = 0;
	while (c.i < size)
	{
		c.key = c.curr->value - min;
		c.index = ((c.key % (size * 2)) + (size * 2)) % (size * 2);
		while (c.table[c.index].seen)
		{
			if (c.table[c.index].value == c.curr->value)
				return (free(c.table), false);
			c.index = (c.index + 1) % (size * 2);
		}
		c.table[c.index].value = c.curr->value;
		c.table[c.index].seen = 1;
		c.curr = c.curr->next;
		c.i++;
	}
	free(c.table);
	return (true);
}
