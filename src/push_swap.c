/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:28:29 by diade-so          #+#    #+#             */
/*   Updated: 2025/05/13 15:35:21 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = valid_and_build_stack(argc, argv);
	if (!a)
		error_exit(NULL, NULL);
	if (!check_duplicate(a->head, a->size, a->min))
	{
		free_stack(a);
		return (1);
	}
	if (is_sorted(a))
		return (1);
	b = create_stack();
	push_swap(a, b);
//	print_stack("a", a);
//	print_stack("b", b);
	free_stack(a);
	free_stack(b);
	return (0);
}
