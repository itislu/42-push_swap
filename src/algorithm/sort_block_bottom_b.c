/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_block_bottom_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:49:16 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 15:50:33 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	seprt_block_bottom_b(t_stacks *stacks, int block_size, int amounts[]);

bool	sort_block_bottom_b(t_stacks *stacks, t_lifo **tasks)
{
	int	amounts[4];

	if (is_empty(stacks->top_b, (*tasks)->block_size, get_next))
	{
		(*tasks)->quadrant = TOP_B;
		return (sort_block_top_b(stacks, tasks));
	}
	ft_bzero(amounts, 4 * sizeof(int));
	find_pos_sorted(stacks->bottom_b, (*tasks)->block_size, get_prev);
	if ((*tasks)->block_size <= 3)
		sort_rest_bottom_b(stacks, tasks);
	else
	{
		seprt_block_bottom_b(stacks, (*tasks)->block_size, amounts);
		if (!add_amounts_to_tasks(tasks, amounts))
			return (lifo_lstclear(tasks), false);
	}
	return (true);
}

void	seprt_block_bottom_b(t_stacks *stacks, int block_size, int amounts[])
{
	int	i;

	i = 0;
	while (i < block_size)
	{
		if (stacks->bottom_b->pos_sorted <= block_size / 3)
			bottom_b_to_bottom_a(stacks, amounts);
		else if (stacks->bottom_b->pos_sorted <= block_size / 3 * 2)
			bottom_b_to_top_b(stacks, amounts);
		else
			bottom_b_to_top_a(stacks, amounts);
		i++;
	}
}
