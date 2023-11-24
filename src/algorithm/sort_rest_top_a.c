#include "push_swap.h"

void	sort_three_top_a(t_heads *heads);

void	sort_rest_top_a(t_heads *heads, t_lifo **protocol)
{
	if (!is_n_amount_sorted(heads->top_a, (*protocol)->block_size, asc, get_next))
	{
		if ((*protocol)->block_size == 2)
			swap_a(heads);
		else
			sort_three_top_a(heads);
	}
	reset_pos_sorted(heads->top_a, (*protocol)->block_size, get_next);
	lifo_lstclear_n(protocol, 1);
}

void	sort_three_top_a(t_heads *heads)
{
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
