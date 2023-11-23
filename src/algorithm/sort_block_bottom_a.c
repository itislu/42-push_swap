#include "push_swap.h"

void	separate_block_bottom_a(t_heads *heads, int block_size);

bool	sort_block_bottom_a(t_heads *heads, t_lifo **protocol)
{
	find_pos_sorted(heads->bottom_a, (*protocol)->block_size, get_prev);
	if ((*protocol)->block_size <= 3)
		sort_rest_bottom_a(heads, protocol);
	else
	{
		separate_block_bottom_a(heads, (*protocol)->block_size);
		lifo_lstclear_n(protocol, 1);
		if (!add_amounts_to_protocol_bottom_a(protocol, (*protocol)->block_size))
			return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(protocol), false);
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
			rotate_b(heads);
		}
		else if (heads->bottom_a->pos_sorted <= block_size / 3 * 2)
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
}
