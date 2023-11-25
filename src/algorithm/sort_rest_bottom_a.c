#include "push_swap.h"

void	sort_three_bottom_a(t_heads *heads);

void	sort_rest_bottom_a(t_heads *heads, t_lifo **tasks)
{
	if (is_n_amount_sorted(heads->bottom_a, (*tasks)->block_size, desc, get_prev))
		while ((*tasks)->block_size-- > 0)
			reverse_rotate_a(heads);
	else
	{
		if ((*tasks)->block_size == 2)
		{
			reverse_rotate_a(heads);
			reverse_rotate_a(heads);
			swap_a(heads);
		}
		else
			sort_three_bottom_a(heads);
	}
	lifo_lstclear_n(tasks, 1);
}

//TODO: work with if x == y - 2 etc for comparison checks to optimize
void	sort_three_bottom_a(t_heads *heads)
{
	if(is_n_amount_sorted(heads->bottom_a, 3, asc, get_prev))
	{
		reverse_rotate_a(heads);
		push_b(heads);
		reverse_rotate_a(heads);
		reverse_rotate_a(heads);
		swap_a(heads);
		push_a(heads);
	}
	else
	{
		reverse_rotate_a(heads);
		reverse_rotate_a(heads);
		if (!is_n_amount_sorted(heads->top_a, 2, asc, get_next))
			swap_a(heads);
		reverse_rotate_a(heads);
		if (!is_n_amount_sorted(heads->top_a, 2, asc, get_next))
			swap_a(heads);
		if (!is_n_amount_sorted(heads->top_a, 3, asc, get_next))
		{
			rotate_a(heads);
			swap_a(heads);
			reverse_rotate_a(heads);
		}
	}
}
