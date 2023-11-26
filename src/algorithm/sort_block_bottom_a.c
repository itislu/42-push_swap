/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_block_bottom_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:49:18 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 18:07:47 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	seprt_block_bottom_a(t_stacks *stacks, int block_size, int amounts[]);

bool	sort_block_bottom_a(t_stacks *stacks, t_lifo **tasks)
{
	int	amounts[4];

	if (is_empty(stacks->top_a, (*tasks)->block_size, get_next))
	{
		(*tasks)->quadrant = TOP_A;
		return (sort_block_top_a(stacks, tasks));
	}
	ft_bzero(amounts, 4 * sizeof(int));
	find_pos_sorted(stacks->bottom_a, (*tasks)->block_size, get_prev);
	if ((*tasks)->block_size <= 3)
		sort_rest_bottom_a(stacks, tasks);
	else
	{
		seprt_block_bottom_a(stacks, (*tasks)->block_size, amounts);
		if (!add_amounts_to_tasks(tasks, amounts))
			return (lifo_lstclear(tasks), false);
	}
	return (true);
}

void	seprt_block_bottom_a(t_stacks *stacks, int block_size, int amounts[])
{
	int	i;

	i = 0;
	while (i < block_size)
	{
		if (stacks->bottom_a->pos_sorted <= block_size / 3)
			bottom_a_to_bottom_b(stacks, amounts);
		else if (stacks->bottom_a->pos_sorted <= block_size / 3 * 2)
			bottom_a_to_top_b(stacks, amounts);
		else
			bottom_a_to_top_a(stacks, amounts);
		i++;
	}
}
