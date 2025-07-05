/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:06:58 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 22:24:24 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->head = s->head->next;
	s->tail = s->tail->next;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
