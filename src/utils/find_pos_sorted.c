/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:06:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 11:03:18 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_pos_sorted(t_list_d *start, int block_size, t_trv get_next)
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
		while (cur->pos_sorted)
		{
			cur = get_next(cur);
			j++;
		}
		lowest = cur;
		cur = get_next(cur);
		while (++j < block_size)
		{
			if (!cur->pos_sorted && (long)cur->content < (long)lowest->content)
				lowest = cur;
			cur = get_next(cur);
		}
		lowest->pos_sorted = i;
	}
}
