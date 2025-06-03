/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:13:41 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/02 17:24:50 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_int_arr(int count, int *arr)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void	print_stack(const char *name, t_stack *s)
{
	int		i;
	t_node	*current;

	if (!s || s->head == NULL)
	{
		printf("List is empty.\n");
		return ;
	}
	printf("%s: ", name);
	current = s->head;
	i = 0;
	while (current && i < s->size)
	{
		printf("%d ", current->value);
		current = current->next;
		i++;
	}
	if (i != s->size)
		printf("[Warning: printed %d nodes, expected %d]", i, s->size);
	printf("\n");
}
