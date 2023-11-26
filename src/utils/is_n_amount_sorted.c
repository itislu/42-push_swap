/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_n_amount_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:38:30 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 23:38:31 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_n_amount_sorted(t_list_d *cur, int n, t_cmp ord, t_trv get_next)
{
	t_list_d	*next;

	if (n == 1)
		return (true);
	while (n > 1)
	{
		next = get_next(cur);
		if (next && !ord((long) cur->content, (long) next->content))
			break ;
		cur = next;
		n--;
	}
	if (n > 1)
		return (false);
	else
		return (true);
}
