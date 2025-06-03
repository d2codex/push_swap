/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:17:29 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/09 17:03:54 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**validate_single_input(char *input_str)
{
	char	**input_arr;
	int		*int_arr;
	int		size;

	input_arr = ft_split(input_str, ' ');
	if (!input_arr[0])
		error_exit(input_arr, NULL);
	if (!is_valid_array(input_arr))
		error_exit(input_arr, NULL);
	size = count_elements(input_arr);
	int_arr = str_to_int_array(size, input_arr);
	if (!int_arr)
		error_exit(input_arr, NULL);
//	if (!check_duplicate(size, int_arr))
//		error_exit(input_arr, int_arr);
	free(int_arr);
	return (input_arr);
}

char	**validate_multiple_input(char **argv)
{
	int	size;
	int	*int_arr;

	if (!is_valid_array(argv))
		error_exit(NULL, NULL);
	size = count_elements(argv);
	int_arr = str_to_int_array(size, argv);
	if (!int_arr)
		error_exit(NULL, NULL);
//	if (!check_duplicate(size, int_arr))
//		error_exit(NULL, int_arr);
	free(int_arr);
	return (argv);
}

char	**validate_input(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error\n");
		exit (1);
	}
	else if (argc == 2)
		return (validate_single_input(argv[1]));
	else
		return (validate_multiple_input(argv + 1));
}
