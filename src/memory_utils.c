/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:44:37 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/04 17:59:48 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error_exit(char **strs, int *arr)
{
	if (strs)
		free_str_array(strs);
	if (arr)
		free(arr);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *s)
{
	int		i;
	t_node	*current;
	t_node	*next;

	if (s->head == NULL)
	{
		free(s);
		return ;
	}
	current = s->head;
	i = 0;
	while (i < s->size)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	free(s);
}
