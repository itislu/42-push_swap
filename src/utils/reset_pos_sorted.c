/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_pos_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:48:34 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 17:32:52 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_pos_sorted(t_list_d *cur, t_trv get_next)
{
	while (cur && cur->pos_sorted)
	{
		cur->pos_sorted = 0;
		cur = get_next(cur);
	}
}
