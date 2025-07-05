/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:04:32 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 13:12:38 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long int	str_to_int(char *str)
{
	int			i;
	long int	sign;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
		result = result * 10 + (str[i++] - '0');
	return (result *= sign);
}

int	is_valid_int(char *str)
{
	long int	num;

	if (!is_valid_input(str))
		return (0);
	num = str_to_int(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	is_valid_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i][0] == '\0')
			return (0);
		if (!is_valid_int(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

void print_hash_table(t_hash *table, int table_size)
{
    for (int i = 0; i < table_size; i++)
    {
        if (table[i].seen)
            printf("Index %d: %d\n", i, table[i].value);
        else
            printf("Index %d: [empty]\n", i);
    }
}

void	init_table(t_hash *table, int table_size)
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
	t_hash	*table;
	t_node	*curr;
	int	key;
	int	index;
	int	i;

	table = malloc((size * 2) * sizeof (t_hash));
	if (!table)
		exit (1);
	curr = head;
	init_table(table, size * 2);
	i = 0;
	while (i < size)
	{
		key = curr->value - min;
//		index = key % (size * 2);
		index = ((key % (size * 2)) + (size * 2)) % (size * 2);
		while (table[index].seen)
		{
			if (table[index].value == curr->value)
			{
				write(1, "Error. Duplicate\n", 17);
				free (table);
				return (false);
			}
			index = (index + 1) % (size * 2);
		}	
		table[index].value = curr->value;
		table[index].seen = 1;
		curr = curr->next;
		i++;
	}
	free(table);
	return (true);
}
