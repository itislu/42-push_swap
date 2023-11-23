#include "push_swap.h"

int	separate_block_top_b(t_heads *heads, int block_size, t_lifo **protocol);

bool	sort_block_top_b(t_heads *heads, t_lifo **protocol)
{
	find_pos_sorted(heads->top_b, (*protocol)->block_size, get_next);
	if ((*protocol)->block_size <= 3)
		sort_rest_top_b(heads, protocol);
	else if (!separate_block_top_b(heads, (*protocol)->block_size, protocol))
		return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(protocol), false);
	return (true);
}

int	separate_block_top_b(t_heads *heads, int block_size, t_lifo **protocol)
{
	int	i;

	i = 0;
	while (i < block_size)
	{
		if (heads->top_b->pos_sorted <= block_size / 3)
		{
			rotate_b(heads);
		}
		else if (heads->top_b->pos_sorted <= block_size / 3 * 2)
		{
			push_a(heads);
			rotate_a(heads);
		}
		else
		{
			push_a(heads);
		}
		i++;
	}
	lifo_lstclear_n(protocol, 1);
	if (!add_amounts_to_protocol_top_b(protocol, block_size))
		return (false);
	return (true);
}
