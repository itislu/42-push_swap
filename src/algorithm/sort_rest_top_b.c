#include "push_swap.h"

void	sort_three_top_b(t_heads *heads);

void	sort_rest_top_b(t_heads *heads, t_lifo **tasks)
{
	if (is_n_amount_sorted(heads->top_b, (*tasks)->block_size, desc, get_next))
		while ((*tasks)->block_size-- > 0)
			push_a(heads);
	else
	{
		if ((*tasks)->block_size == 2)
		{
			swap_b(heads);
			push_a(heads);
			push_a(heads);
		}
		else
			sort_three_top_b(heads);
	}
	lifo_lstclear_n(tasks, 1);
}

void	sort_three_top_b(t_heads *heads)
{
	if (!is_n_amount_sorted(heads->top_b, 2, desc, get_next))
		swap_b(heads);
	push_a(heads);
	if (!is_n_amount_sorted(heads->top_b, 2, desc, get_next))
		swap_b(heads);
	push_a(heads);
	if (!is_n_amount_sorted(heads->top_a, 2, asc, get_next))
		swap_a(heads);
	push_a(heads);
	if (!is_n_amount_sorted(heads->top_a, 2, asc, get_next))
		swap_a(heads);
}
