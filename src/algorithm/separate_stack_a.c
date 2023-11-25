/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_block_initial_top_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:59:15 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 22:09:50 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	separate_block_initial_top_a(t_heads *heads, int block_size, t_lifo **tasks);

bool	separate_stack_a(t_heads *heads, t_lifo **tasks)
{
	int	block_size;

	block_size = (*tasks)->block_size;
	lifo_lstclear_n(tasks, 1);
	if (is_n_amount_sorted(heads->top_a, block_size, asc, get_next))
		return (true);
	if (!separate_block_initial_top_a(heads, block_size, tasks))
		return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(tasks), false);
	return (true);
}

/* First splitting can be done recursively bc TOP_A is feeding itself only the highest thirds. */
bool	separate_block_initial_top_a(t_heads *heads, int block_size, t_lifo **tasks)
{
	int	i;
	int	amounts[4];

	ft_bzero(amounts, 4 * sizeof(int));
	if(block_size <= 3)	// Would be great to stop earlier, with 4 or 5
	{
		if (!add_new_task(tasks, block_size, TOP_A))
			return (false);
		return (true);
	}
	find_pos_sorted(heads->top_a, block_size, get_next);
	i = 0;
	while (i++ < block_size)
	{
		if (heads->top_a->pos_sorted <= block_size / 3)
			top_a_to_bottom_b(heads, amounts);
		else if (heads->top_a->pos_sorted <= block_size / 3 * 2)
			top_a_to_top_b(heads, amounts);
		else
			top_a_to_bottom_a(heads, amounts);
	}
	if (!add_new_task(tasks, amounts[BOTTOM_B], BOTTOM_B))
		return (false);
	if (!add_new_task(tasks, amounts[TOP_B], TOP_B))
		return (false);
	return (separate_block_initial_top_a(heads, block_size - block_size / 3 * 2, tasks));
}
