/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:48:01 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/06 15:49:41 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	rev_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

int	exec_ops(char *line, t_stack *a, t_stack *b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		swap_both(a, b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(line, "rrb\n", 3) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(line, "rrr\n", 3) == 0)
		rev_rotate_both(a, b);
	else
		return (0);
	return (1);
}
