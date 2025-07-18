/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:04:32 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/06 23:14:53 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
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
