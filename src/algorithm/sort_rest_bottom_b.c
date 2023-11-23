#include "push_swap.h"

void	sort_three_bottom_b(t_heads *heads);

void	sort_rest_bottom_b(t_heads *heads, t_lifo **protocol)
{
	if (is_n_amount_sorted(heads->bottom_b, (*protocol)->block_size, desc, get_prev))
	{
		while ((*protocol)->block_size-- > 0)
		{
			reverse_rotate_b(heads);
			push_a(heads);
		}
	}
	else
	{
		if ((*protocol)->block_size == 2)
		{
			reverse_rotate_b(heads);
			reverse_rotate_b(heads);
			push_a(heads);
			push_a(heads);
		}
		else
			sort_three_bottom_b(heads);
	}
	lifo_lstclear_n(protocol, 1);
}

void	sort_three_bottom_b(t_heads *heads)
{
	if(is_n_amount_sorted(heads->bottom_b, 3, asc, get_prev))
	{
		reverse_rotate_b(heads);
		reverse_rotate_b(heads);
		reverse_rotate_b(heads);
		push_a(heads);
		push_a(heads);
		push_a(heads);
	}
	else
	{
		reverse_rotate_b(heads);
		reverse_rotate_b(heads);
		if (!is_n_amount_sorted(heads->top_b, 2, desc, get_next))
			swap_b(heads);
		push_a(heads);
		// Check if bottom is higher than top
		reverse_rotate_b(heads);
		// Else push and then rotate
		if (!is_n_amount_sorted(heads->top_b, 2, desc, get_next))
			swap_b(heads);
		push_a(heads);
		if (!is_n_amount_sorted(heads->top_a, 2, asc, get_next))
			swap_a(heads);
		push_a(heads);
	}
}
