/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:00 by diade-so          #+#    #+#             */
/*   Updated: 2025/07/05 13:10:31 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				cost_a;
	int				cost_b;
	int				dir_a;
	int				dir_b;
	int				total_cost;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	int		min;	
	int		max;
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct	s_hash
{
	int	value;
	char	seen;
}	t_hash;

// prototype for print_utils.c
void		print_int_arr(int count, int *arr);
void		print_stack(const char *name, t_stack *s);

// prototype for validate_input1.c
int			is_valid_input(char *str);
long int	str_to_int(char *str);
int			is_valid_int(char *str);
int			is_valid_array(char **arr);
void		init_table(t_hash *table, int table_size);
bool		check_duplicate(t_node *head, int size, int min);

//prototypes for validate_input2.c
char		**validate_single_input(char *input_str);
char		**validate_multiple_input(char **argv);
char		**validate_input(int argc, char **argv);

// prototypes for array_utils.c
int			*str_to_int_array(int size, char **str);
int			count_elements(char **arr);

// prototypes for stack_utils.c
void		init_stack(t_stack *s);
t_node		*create_node(int value);
void		append_node(t_stack *s, int value);

// prototypes for stack_creation.c
void		fill_stack(t_stack *s, int *arr, int size);
t_stack		*create_stack(void);
t_stack		*valid_and_build_stack(int argc, char **argv);
int			is_sorted(t_stack *s);

// prototypes for memory_utils.c
void		free_str_array(char **arr);
void		error_exit(char **strs, int *arr);
void		free_stack(t_stack *s);

// protoypes for swap.c operations
void		swap(t_stack *s);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

// prototypes for push.c operations
void		push(t_stack *src, t_stack *dst);
void		adjust_src(t_stack *src);
void		adjust_dst(t_stack *dst, t_node *node);
void		pb_to_a(t_stack *b, t_stack *a);
void		pa_to_b(t_stack *a, t_stack *b);

// prototypes for push_utils.c
void		update_min_max(t_stack *s, int value);
void		update_min_max_after_push(t_stack *s);

// prototypes for rotate.c operations
void		rotate(t_stack *s);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);

// prototypes for reverse_rotate.c 
void		reverse_rotate(t_stack *s);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

// prototypes for sort.c (execute algorithm)
void		sort_2(t_stack *s);
void		sort_3(t_stack *s);
void		sort_5(t_stack *a, t_stack *b);
int		count_push_limit(t_stack *a, int range_max);
void		sort_partial(t_stack *a, t_stack *b);
void		push_swap(t_stack *a, t_stack *b);

// prototypes for calculations1.c
int			calc_rotation_cost(int pos, int size, int *dir);
void		apply_node_costs(t_node *node, int pos, t_stack *a, t_stack *b);
t_node		*find_best_node(t_stack *a, t_stack *b, int range_max);

// prototypes for calculations2.c
int			get_insert_pos_b(t_stack *b, int value);
void		exec_rotation(t_stack *a, t_stack *b, t_node *node);
void		do_a_rotations(t_stack *a, int remaining, int dir_a);
void		do_b_rotations(t_stack *b, int remaining, int dir_b);

// prototypes for calculations3.c
int			get_value_pos(t_stack *s, int value);
void		rotate_to_pos_a(t_stack *a, int pos);
void		rotate_to_pos_b(t_stack *b, int pos);
void		push_back_to_a(t_stack *a, t_stack *b);

#endif
