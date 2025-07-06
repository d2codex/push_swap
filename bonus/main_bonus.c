/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:55:30 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/06 23:26:53 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_input_data	d;

	init_data(&d);
	d.input_arr = get_args(ac, av);
	if (!d.input_arr)
		return (pr_errf(NULL, NULL, NULL, NULL), 1);
	if (!is_valid_array(d.input_arr))
		return (pr_errf(d.input_arr, NULL, NULL, NULL), 1);
	d.size = count_elements(d.input_arr);
	d.int_arr = atoi_arr(d.size, d.input_arr);
	if (!d.int_arr)
		return (clean(d.input_arr, NULL, NULL, NULL), 1);
	d.a = create_stack();
	if (!d.a)
		return (clean(d.input_arr, d.int_arr, NULL, NULL), 1);
	fill_stack(d.a, d.int_arr, d.size);
	if (!check_duplicate(d.a->head, d.a->size, d.a->min))
		return (pr_errf(d.input_arr, d.int_arr, d.a, NULL), 1);
	d.b = create_stack();

	if (!read_exec_ops(d.a, d.b))
		return (pr_errf(d.input_arr, d.int_arr, d.a, d.b), 1);
	check_print_results(d.a, d.b);
	clean(d.input_arr, d.int_arr, d.a, d.b);
	return (0);
}
