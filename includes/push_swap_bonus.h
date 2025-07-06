/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:57:36 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/06 16:54:01 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "push_swap.h"

// prototypes for checker_bonus.c
int	read_exec_ops(t_stack *a, t_stack *b);
void	check_print_results(t_stack *a, t_stack *b);

// prototypes for operations.c
void    swap_both(t_stack *a, t_stack *b);
void    rotate_both(t_stack *a, t_stack *b);
void    rev_rotate_both(t_stack *a, t_stack *b);
int	exec_ops(char *line, t_stack *a, t_stack *b);

#endif
