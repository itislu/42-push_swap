/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_bottom_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:49:08 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 18:08:23 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_bottom_a(t_stacks *stacks);

void	sort_rest_bottom_a(t_stacks *stacks, t_lifo **tasks)
{
	if (is_n_amount_sorted(stacks->bottom_a, (*tasks)->block_size,
			desc, get_prev))
		while ((*tasks)->block_size-- > 0)
			reverse_rotate_a(stacks);
	else
	{
		if ((*tasks)->block_size == 2)
		{
			reverse_rotate_a(stacks);
			reverse_rotate_a(stacks);
			swap_a(stacks);
		}
		else
			sort_three_bottom_a(stacks);
	}
	lifo_lstclear_n(tasks, 1);
}

void	sort_three_bottom_a(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	if (stacks->top_a->pos_sorted == 1)
		push_b(stacks);
	reverse_rotate_a(stacks);
	if (!is_n_amount_sorted(stacks->top_a, 2, asc, get_next))
		swap_a(stacks);
	if (stacks->bottom_a->pos_sorted == 3 && stacks->top_a->pos_sorted != 2)
		push_b(stacks);
	reverse_rotate_a(stacks);
	if (!is_n_amount_sorted(stacks->top_a, 2, asc, get_next))
		swap_a(stacks);
	if (stacks->top_a->pos_sorted != 1)
		push_a(stacks);
}
