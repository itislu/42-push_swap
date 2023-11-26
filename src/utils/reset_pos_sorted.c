/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_pos_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:48:34 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:48:35 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_pos_sorted(t_list_d *cur, int block_size, t_trv get_next)
{
	int	i;

	i = 0;
	while (i++ < block_size)
	{
		cur->pos_sorted = 0;
		cur = get_next(cur);
	}
}
