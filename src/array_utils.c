/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:09:27 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 18:07:43 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*atoi_arr(int size, char **str)
{
	int	i;
	int	*int_arr;

	i = 0;
	if (!str)
		return (NULL);
	int_arr = malloc(size * sizeof (int));
	if (!int_arr)
		return (NULL);
	while (i < size)
	{
		int_arr[i] = str_to_int(str[i]);
		i++;
	}
	return (int_arr);
}

int	count_elements(char **arr)
{
	int	size;

	size = 0;
	while (arr[size] != NULL)
		size++;
	return (size);
}
