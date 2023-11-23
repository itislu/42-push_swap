/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_pos_sorted_in_block.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:07:32 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 15:27:04 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos_sorted(t_list_d *start, int block_size, t_next get_next)
{
	t_list_d	*cur;
	t_list_d	*highest;

	while (block_size > 0)
	{
		cur = start;
		while (cur->pos_sorted != 0)
			cur = get_next(cur);
		highest = cur;
		cur = get_next(cur);
		while (cur)
		{
			if (cur->pos_sorted == 0 && cur->content >= highest->content)
				highest = cur;
			cur = get_next(cur);
		}
		highest->pos_sorted = block_size;
		block_size--;
	}
}
