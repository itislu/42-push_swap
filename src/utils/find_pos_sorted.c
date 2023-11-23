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
	int			i;
	int			j;
	t_list_d	*cur;
	t_list_d	*lowest;

	i = 0;
	while (i++ < block_size)
	{
		j = 0;
		cur = start;
		while (cur->pos_sorted != 0)
		{
			cur = get_next(cur);
			j++;
		}
		lowest = cur;
		cur = get_next(cur);
		while (++j < block_size)
		{
			if (cur->pos_sorted == 0 && cur->content < lowest->content)
				lowest = cur;
			cur = get_next(cur);
		}
		lowest->pos_sorted = i;
	}
}
