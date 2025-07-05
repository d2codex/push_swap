/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:39:49 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 17:22:17 by diade-so         ###   ########.fr       */
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

void	init_data(t_input_data *data, t_stack **a, t_stack **b)
{
	data->input_arr = NULL;
	data->int_arr = NULL;
	data->size = 0;
	*a = NULL;
	*b = NULL;
}

char **copy_argv_to_arr(int argc, char **argv)
{
	char	**input_arr;
	int	i;

	if (argc < 2)
		return (NULL);
	input_arr = malloc(sizeof(char *) * argc);
	if (!input_arr)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		input_arr[i - 1] = ft_strdup(argv[i]);
		if (!input_arr[i - 1])
		{
			while (--i > 0)
				free(input_arr[i - 1]);
			free(input_arr);
			return (NULL);
		}
		i++;
	}
	input_arr[i - 1] = NULL;
	return (input_arr);
}

char	**get_input_arr(int argc, char **argv)
{
	char	**input_arr;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		input_arr = ft_split(argv[1], ' ');
		if (!input_arr || !input_arr[0])
		{
			if (input_arr)
				free_str_array(input_arr);
			return (NULL);
		}
	}
	else
	{
		input_arr = copy_argv_to_arr(argc, argv);
		if (!input_arr)
			return (NULL);
	}
	return (input_arr);
}
