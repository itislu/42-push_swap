#include "push_swap.h"

void	separate_block_bottom_a(t_heads *heads, int block_size, int amounts[]);

bool	sort_block_bottom_a(t_heads *heads, t_lifo **tasks)
{
	int	amounts[4];

	ft_bzero(amounts, 4 * sizeof(int));
	find_pos_sorted(heads->bottom_a, (*tasks)->block_size, get_prev);
	if ((*tasks)->block_size <= 3)
		sort_rest_bottom_a(heads, tasks);
	else
	{
		separate_block_bottom_a(heads, (*tasks)->block_size, amounts);
		if (!add_amounts_to_tasks(tasks, amounts))
			return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(tasks), false);
	}
	return (true);
}

void	separate_block_bottom_a(t_heads *heads, int block_size, int amounts[])
{
	int	i;

	i = 0;
	while (i < block_size)
	{
		if (heads->bottom_a->pos_sorted <= block_size / 3)
			bottom_a_to_bottom_b(heads, amounts);
		else if (heads->bottom_a->pos_sorted <= block_size / 3 * 2)
			bottom_a_to_top_b(heads, amounts);
		else
			bottom_a_to_top_a(heads, amounts);
		i++;
	}
}
