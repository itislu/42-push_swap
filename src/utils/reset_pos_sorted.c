#include "push_swap.h"

void	reset_pos_sorted(t_list_d *cur, int block_size, t_next get_next)
{
	int	i;

	i = 0;
	while (i++ < block_size)
	{
		cur->pos_sorted = 0;
		cur = get_next(cur);
	}
}
