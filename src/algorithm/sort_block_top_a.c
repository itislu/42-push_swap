#include "push_swap.h"

void	separate_block_top_a(t_heads *heads, int block_size);

bool	sort_block_top_a(t_heads *heads, t_lifo **tasks)
{
	find_pos_sorted(heads->top_a, (*tasks)->block_size, get_next);
	if ((*tasks)->block_size <= 3)
		sort_rest_top_a(heads, tasks);
	else
	{
		separate_block_top_a(heads, (*tasks)->block_size);
		if (!add_amounts_to_tasks(tasks, (*tasks)->block_size))
			return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(tasks), false);
	}
	return (true);
}

void	separate_block_top_a(t_heads *heads, int block_size)
{
	int	i;

	i = 0;
	while (i < block_size)
	{
		if (heads->top_a->pos_sorted <= block_size / 3)
		{
			push_b(heads);
			rotate_b(heads);
		}
		else if (heads->top_a->pos_sorted <= block_size / 3 * 2)
		{
			rotate_a(heads);
		}
		else
		{
			push_b(heads);
		}
		i++;
	}
}
