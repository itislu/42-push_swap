/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:02 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 23:59:56 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_MSG "Error\n"

# include <stdbool.h>

# define TOP_A 0
# define TOP_B 1
# define BOTTOM_A 2
# define BOTTOM_B 3

typedef struct s_list_d
{
	void			*content;
	int				pos_origin;
	int				pos_sorted;
	struct s_list_d	*prev;
	struct s_list_d	*next;
}	t_list_d;

typedef struct s_heads
{
	t_list_d	*top_a;
	t_list_d	*top_b;
	t_list_d	*bottom_a;
	t_list_d	*bottom_b;
}	t_heads;

typedef struct s_lifo
{
	int				block_size;
	char			quadrant;
	struct s_lifo	*next;
}	t_lifo;

typedef t_list_d	*(*t_trv)(t_list_d *);

typedef bool	(*t_cmp)(long, long);

# include "libft.h"
# include "ft_printf.h"

/* Algorithm */
bool		sort_block_bottom_a(t_heads *heads, t_lifo **tasks);
bool		sort_block_bottom_b(t_heads *heads, t_lifo **tasks);
bool		separate_stack_a(t_heads *heads, t_lifo **tasks);
bool		sort_block_top_a(t_heads *heads, t_lifo **tasks);
bool		sort_block_top_b(t_heads *heads, t_lifo **tasks);
void		sort_rest_bottom_a(t_heads *heads, t_lifo **tasks);
void		sort_rest_bottom_b(t_heads *heads, t_lifo **tasks);
void		sort_rest_top_a(t_heads *heads, t_lifo **tasks);
void		sort_rest_top_b(t_heads *heads, t_lifo **tasks);

/* Checks */
int			parsing(int argc, char *argv[], t_list_d **top_a, int count);
int			bigger_than_integer(t_list_d *head);
int			check_duplicates(t_list_d *head_a);

/* LIFO */
void		lifo_lstadd_front(t_lifo **head, t_lifo *new);
void		lifo_lstclear(t_lifo **head);
void		lifo_lstclear_n(t_lifo **head, int n);
t_lifo		*lifo_lstnew(int amount, char quadrant);

/* Movement */
void		bottom_a_to_bottom_b(t_heads *heads, int amounts[]);
void		bottom_a_to_top_a(t_heads *heads, int amounts[]);
void		bottom_a_to_top_b(t_heads *heads, int amounts[]);
void		bottom_b_to_bottom_a(t_heads *heads, int amounts[]);
void		bottom_b_to_top_a(t_heads *heads, int amounts[]);
void		bottom_b_to_top_b(t_heads *heads, int amounts[]);
void		top_a_to_bottom_a(t_heads *heads, int amounts[]);
void		top_a_to_bottom_b(t_heads *heads, int amounts[]);
void		top_a_to_top_b(t_heads *heads, int amounts[]);
void		top_b_to_bottom_a(t_heads *heads, int amounts[]);
void		top_b_to_bottom_b(t_heads *heads, int amounts[]);
void		top_b_to_top_a(t_heads *heads, int amounts[]);

/* Operations */
void		swap_a(t_heads *heads);
void		swap_b(t_heads *heads);
void		swap_both(t_heads *heads);
void		push_a(t_heads *heads);
void		push_b(t_heads *heads);
void		rotate_a(t_heads *heads);
void		rotate_b(t_heads *heads);
void		rotate_both(t_heads *heads);
void		reverse_rotate_a(t_heads *heads);
void		reverse_rotate_b(t_heads *heads);
void		reverse_rotate_both(t_heads *heads);

/* Add to tasks */
bool		add_amounts_to_tasks(t_lifo **tasks, int amounts[]);
bool		add_new_task(t_lifo **tasks, int amount, char quadrant);

/* Utils */
void		find_pos_sorted(t_list_d *start, int block_size, t_trv get_next);
bool		is_n_amount_sorted(t_list_d *cur, int n, t_cmp ord, t_trv get_next);
void		reset_pos_sorted(t_list_d *cur, int block_size, t_trv get_next);

/* Function pointers */
bool		asc(long value1, long value2);
bool		desc(long value1, long value2);
bool		asc_contig(long value1, long value2);
bool		desc_contig(long value1, long value2);
t_list_d	*get_next(t_list_d *node);
t_list_d	*get_prev(t_list_d *node);

#endif