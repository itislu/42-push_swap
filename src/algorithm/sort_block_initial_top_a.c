/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_block_initial_top_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:59:15 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 16:38:38 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	separate_block_initial_top_a(t_heads *heads, int block_size, t_lifo **tasks);

bool	sort_block_initial_top_a(t_heads *heads, t_lifo **tasks)
{
	int	block_size;

	block_size = (*tasks)->block_size;
	lifo_lstclear_n(tasks, 1);
	if (is_n_amount_sorted(heads->top_a, block_size, asc, get_next))
		return (true);
	if (!separate_block_initial_top_a(heads, block_size, tasks))
		return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(tasks), false);

	//TODO: Can be made general in all the sort_block functions instead of in each operation.
	/* Reset pos_sorted in case the largest 2 or 3 inputs were already sorted */
	// cur = heads->top_a;
	// while (cur)
	// {
	// 	cur->pos_sorted = 0;
	// 	cur = cur->next;
	// }

	/* amount_left is divisible by 2 now */

	return (true);
}

/* First splitting can be done recursively bc TOP_A is feeding itself only the highest thirds. */
bool	separate_block_initial_top_a(t_heads *heads, int block_size, t_lifo **tasks)
{
	int	i;

	if(block_size <= 3)	// Would be great to stop earlier, with 4 or 5
	{
		if (!add_single_amount_to_tasks(tasks, block_size, TOP_A))
			return (false);
		return (true);
	}
	find_pos_sorted(heads->top_a, block_size, get_next);
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
			push_b(heads);
		}
		else
		{
			rotate_a(heads);
		}
		i++;
	}
	if (!add_amounts_to_tasks_initial_top_a(tasks, block_size))
		return (false);
	return (separate_block_initial_top_a(heads, block_size - block_size / 3 * 2, tasks));
}
