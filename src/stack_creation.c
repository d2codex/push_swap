/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:39:49 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/09 17:00:36 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	fill_stack(t_stack *s, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		append_node(s, arr[i]);
		i++;
	}
}

t_stack	*create_stack(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof (t_stack));
	if (!s)
	{
		printf("Error\n");
		exit (1);
	}
	init_stack(s);
	return (s);
}

t_stack	*valid_and_build_stack(int argc, char **argv)
{
	char	**input_arr;
	int		*int_arr;
	int		size;
	t_stack	*s;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
		input_arr = validate_single_input(argv[1]);
	else
		input_arr = validate_multiple_input(argv + 1);
	size = count_elements(input_arr);
	int_arr = str_to_int_array(size, input_arr);
	if (!int_arr)
		error_exit(input_arr, NULL);
	s = create_stack();
	fill_stack(s, int_arr, size);
	if (argc == 2)
		free_str_array(input_arr);
	free(int_arr);
	return (s);
}
