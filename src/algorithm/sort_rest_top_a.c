#include "push_swap.h"

void	sort_three_top_a(t_heads *heads);

void	sort_rest_top_a(t_heads *heads, t_lifo **tasks)
{
	if (!is_n_amount_sorted(heads->top_a, (*tasks)->block_size, asc, get_next))
	{
		if ((*tasks)->block_size == 2)
			swap_a(heads);
		else
			sort_three_top_a(heads);
	}
	reset_pos_sorted(heads->top_a, (*tasks)->block_size, get_next);
	lifo_lstclear_n(tasks, 1);
}

void	sort_three_top_a(t_heads *heads)
{
	if (heads->top_a->next == heads->bottom_a->prev)
	{
		if (is_n_amount_sorted(heads->top_a, 2, asc, get_next))
			reverse_rotate_a(heads);
		else if ((long) heads->top_a->content > (long) heads->bottom_a->content)
			rotate_a(heads);
	}
	if (!is_n_amount_sorted(heads->top_a, 2, asc, get_next))
		swap_a(heads);
	if (!is_n_amount_sorted(heads->top_a->next, 2, asc, get_next))
	{
		push_b(heads);
		swap_a(heads);
		push_a(heads);
		if (!is_n_amount_sorted(heads->top_a, 2, asc, get_next))
			swap_a(heads);
	}
}
