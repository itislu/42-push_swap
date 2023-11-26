/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:19:35 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 13:30:56 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_empty(t_list_d *cur, int block_size, t_trv get_next)
{
	int	i;

	i = 0;
	while (i < block_size)
	{
		cur = get_next(cur);
		i++;
	}
	if (cur == NULL)
		return (true);
	else
		return (false);
}
