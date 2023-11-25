#include "push_swap.h"

void	separate_block_top_b(t_heads *heads, int block_size, int amounts[]);

bool	sort_block_top_b(t_heads *heads, t_lifo **tasks)
{
	int	amounts[4];

	ft_bzero(amounts, 4 * sizeof(int));
	find_pos_sorted(heads->top_b, (*tasks)->block_size, get_next);
	if ((*tasks)->block_size <= 3)
		sort_rest_top_b(heads, tasks);
	else
	{
		separate_block_top_b(heads, (*tasks)->block_size, amounts);
		if (!add_amounts_to_tasks(tasks, amounts))
			return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(tasks), false);
	}
	return (true);
}

void	separate_block_top_b(t_heads *heads, int block_size, int amounts[])
{
	int	i;

	i = 0;
	while (i < block_size)
	{
		if (heads->top_b->pos_sorted <= block_size / 3)
			top_b_to_bottom_b(heads, amounts);
		else if (heads->top_b->pos_sorted <= block_size / 3 * 2)
			top_b_to_bottom_a(heads, amounts);
		else
			top_b_to_top_a(heads, amounts);
		i++;
	}
}
