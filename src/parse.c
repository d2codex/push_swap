/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:39:49 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/06 23:23:36 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	init_data(t_input_data *data)
{
	data->input_arr = NULL;
	data->int_arr = NULL;
	data->size = 0;
	data->a = NULL;
	data->b = NULL;
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

int	is_whitespace_only(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**get_args(int argc, char **argv)
{
	char	**input_arr;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		if (!argv[1] || is_whitespace_only(argv[1]))
			return (NULL);
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

int	is_sorted(t_stack *s)
{
	t_node	*current;

	if (s->size < 2)
		return (1);
	current = s->head;
	while (current->next != s->head)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
