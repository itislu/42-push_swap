/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:59:15 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 15:47:51 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	seprt_top_a_rcrsv(t_stacks *stacks, int block_size, t_lifo **tasks);

bool	separate_stack_a(t_stacks *stacks, t_lifo **tasks)
{
	int	block_size;

	block_size = (*tasks)->block_size;
	lifo_lstclear_n(tasks, 1);
	if (is_n_amount_sorted(stacks->top_a, block_size, asc, get_next))
		return (true);
	if (!seprt_top_a_rcrsv(stacks, block_size, tasks))
		return (lifo_lstclear(tasks), false);
	return (true);
}

/**
 * First splitting can be done recursively bc top_a is feeding itself only the
 * highest thirds.
 */
bool	seprt_top_a_rcrsv(t_stacks *stacks, int block_size, t_lifo **tasks)
{
	int	i;
	int	amounts[4];

	ft_bzero(amounts, 4 * sizeof(int));
	if (block_size <= 3)
	{
		if (!add_new_task(tasks, block_size, TOP_A))
			return (false);
		return (true);
	}
	find_pos_sorted(stacks->top_a, block_size, get_next);
	i = 0;
	while (i++ < block_size
		&& !is_n_amount_sorted(stacks->top_a, block_size, asc_contig, get_next))
	{
		if (stacks->top_a->pos_sorted <= block_size / 3)
			top_a_to_bottom_b(stacks, amounts);
		else if (stacks->top_a->pos_sorted <= block_size / 3 * 2)
			top_a_to_top_b(stacks, amounts);
		else
			top_a_to_bottom_a(stacks, amounts);
	}
	if (!add_2_new_tasks(tasks, amounts, BOTTOM_B, TOP_B))
		return (false);
	return (seprt_top_a_rcrsv(stacks, block_size - block_size / 3 * 2, tasks));
}
