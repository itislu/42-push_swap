/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:02 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/27 01:00:09 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# define ERROR_MSG "Error\n"
# define TOP_A 0
# define TOP_B 1
# define BOTTOM_A 2
# define BOTTOM_B 3

/* Structs */
typedef struct s_stacks
{
	t_list_d	*top_a;
	t_list_d	*top_b;
	t_list_d	*bottom_a;
	t_list_d	*bottom_b;
}	t_stacks;

typedef struct s_lifo
{
	int				block_size;
	char			quadrant;
	struct s_lifo	*next;
}	t_lifo;

/* Function pointers */
typedef t_list_d	*(*t_trv)(t_list_d *);
typedef bool		(*t_cmp)(long, long);

/* Algorithm */
bool		sort_block_bottom_a(t_stacks *stacks, t_lifo **tasks);
bool		sort_block_bottom_b(t_stacks *stacks, t_lifo **tasks);
bool		separate_stack_a(t_stacks *stacks, t_lifo **tasks);
bool		sort_block_top_a(t_stacks *stacks, t_lifo **tasks);
bool		sort_block_top_b(t_stacks *stacks, t_lifo **tasks);
void		sort_rest_bottom_a(t_stacks *stacks, t_lifo **tasks);
void		sort_rest_bottom_b(t_stacks *stacks, t_lifo **tasks);
void		sort_rest_top_a(t_stacks *stacks, t_lifo **tasks);
void		sort_rest_top_b(t_stacks *stacks, t_lifo **tasks);

/* Checks */
bool		check_bad_input(int argc, char *argv[]);
int			check_bigger_than_integer(t_list_d *cur);
int			check_duplicates(t_list_d *to_check);
bool		check_malloc_errors(t_stacks *stacks, int input_count);

/* Last In, First Out */
void		lifo_lstadd_front(t_lifo **head, t_lifo *new);
void		lifo_lstclear(t_lifo **head);
void		lifo_lstclear_n(t_lifo **head, int n);
t_lifo		*lifo_lstnew(int amount, char quadrant);

/* Movement */
void		bottom_a_to_bottom_b(t_stacks *stacks, int amounts[]);
void		bottom_a_to_top_a(t_stacks *stacks, int amounts[]);
void		bottom_a_to_top_b(t_stacks *stacks, int amounts[]);
void		bottom_b_to_bottom_a(t_stacks *stacks, int amounts[]);
void		bottom_b_to_top_a(t_stacks *stacks, int amounts[]);
void		bottom_b_to_top_b(t_stacks *stacks, int amounts[]);
void		top_a_to_bottom_a(t_stacks *stacks, int amounts[]);
void		top_a_to_bottom_b(t_stacks *stacks, int amounts[]);
void		top_a_to_top_b(t_stacks *stacks, int amounts[]);
void		top_b_to_bottom_a(t_stacks *stacks, int amounts[]);
void		top_b_to_bottom_b(t_stacks *stacks, int amounts[]);
void		top_b_to_top_a(t_stacks *stacks, int amounts[]);

/* Operations */
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);
void		swap_both(t_stacks *stacks);
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rotate_both(t_stacks *stacks);
void		reverse_rotate_a(t_stacks *stacks);
void		reverse_rotate_b(t_stacks *stacks);
void		reverse_rotate_both(t_stacks *stacks);

/* Parsing */
void		init_stacks(t_stacks *stacks, int argc, char *argv[], int *incount);
bool		parsing(int argc, char *argv[], t_stacks *stacks, int *input_count);

/* Tasks */
bool		add_2_new_tasks(t_lifo **tasks, int amounts[], int qu1, int qu2);
bool		add_amounts_to_tasks(t_lifo **tasks, int amounts[]);
bool		add_new_task(t_lifo **tasks, int amount, char quadrant);

/* Utils */
void		find_pos_sorted(t_list_d *start, int block_size, t_trv get_next);
bool		is_empty(t_list_d *cur, int block_size, t_trv get_next);
bool		is_n_amount_sorted(t_list_d *cur, int n, t_cmp ord, t_trv get_next);
void		reset_pos_sorted(t_list_d *cur, t_trv get_next);

/* Function pointers */
bool		asc(long value1, long value2);
void		del(void *nothing);
bool		desc(long value1, long value2);
bool		asc_contig(long value1, long value2);
bool		desc_contig(long value1, long value2);
t_list_d	*get_next(t_list_d *node);
t_list_d	*get_prev(t_list_d *node);

#endif