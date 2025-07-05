/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:28:29 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 17:21:58 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	t_input_data	data;
	t_stack		*a;
	t_stack		*b;

	init_data(&data, &a, &b);
	data.input_arr = get_input_arr(argc, argv);
	if (!data.input_arr)
		return (1);
	if (!is_valid_array(data.input_arr))
		return (perror_and_free(data.input_arr, NULL, NULL, NULL), 1);
	data.size = count_elements(data.input_arr);
	data.int_arr = str_to_int_array(data.size, data.input_arr);
	if (!data.int_arr)
		return (free_allocated(data.input_arr, NULL, NULL, NULL), 1);
	a = create_stack();
	if (!a)
		return (free_allocated(data.input_arr, data.int_arr, NULL, NULL), 1);
	fill_stack(a, data.int_arr, data.size);
	if (!check_duplicate(a->head, a->size, a->min))
		return (perror_and_free(data.input_arr, data.int_arr, a, NULL), 1);
	if (is_sorted(a))
		return (free_allocated(data.input_arr, data.int_arr, a, NULL), 1);
	b = create_stack();
	push_swap(a, b);
	free_allocated(data.input_arr, data.int_arr, a, b);
	return (0);
}

