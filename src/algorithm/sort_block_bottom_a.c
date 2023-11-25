#include "push_swap.h"

void	separate_block_bottom_a(t_heads *heads, int block_size);

bool	sort_block_bottom_a(t_heads *heads, t_lifo **tasks)
{
	find_pos_sorted(heads->bottom_a, (*tasks)->block_size, get_prev);
	if ((*tasks)->block_size <= 3)
		sort_rest_bottom_a(heads, tasks);
	else
	{
		separate_block_bottom_a(heads, (*tasks)->block_size);
		if (!add_amounts_to_tasks(tasks, (*tasks)->block_size))
			return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(tasks), false);
	}
	return (true);
}

void	separate_block_bottom_a(t_heads *heads, int block_size)
{
	int	i;

	i = 0;
	while (i < block_size)
	{
		if (heads->bottom_a->pos_sorted <= block_size / 3)
		{
			reverse_rotate_a(heads);
			push_b(heads);
			rotate_b(heads);
		}
		else if (heads->bottom_a->pos_sorted <= block_size / 3 * 2)
		{
			reverse_rotate_a(heads);
			push_b(heads);
		}
		else
		{
			reverse_rotate_a(heads);
		}
		i++;
	}
}
