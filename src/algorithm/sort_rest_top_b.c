/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_top_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:49:01 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 18:24:35 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_top_b(t_stacks *stacks);

void	sort_rest_top_b(t_stacks *stacks, t_lifo **tasks)
{
	if (is_n_amount_sorted(stacks->top_b, (*tasks)->block_size, desc, get_next))
		while ((*tasks)->block_size-- > 0)
			push_a(stacks);
	else
	{
		if ((*tasks)->block_size == 2)
		{
			swap_b(stacks);
			push_a(stacks);
			push_a(stacks);
		}
		else
			sort_three_top_b(stacks);
	}
	lifo_lstclear_n(tasks, 1);
}

void	sort_three_top_b(t_stacks *stacks)
{
	if (stacks->top_b->next == stacks->bottom_b->prev)
	{
		if (stacks->top_b->next->pos_sorted == 3)
			swap_b(stacks);
		else if (stacks->bottom_b->pos_sorted == 3)
			reverse_rotate_b(stacks);
	}
	if (!is_n_amount_sorted(stacks->top_b, 2, desc, get_next))
		swap_b(stacks);
	push_a(stacks);
	if (!is_n_amount_sorted(stacks->top_b, 2, desc, get_next))
		swap_b(stacks);
	push_a(stacks);
	if (!is_n_amount_sorted(stacks->top_a, 2, asc, get_next))
		swap_a(stacks);
	push_a(stacks);
	if (!is_n_amount_sorted(stacks->top_a, 2, asc, get_next))
		swap_a(stacks);
}
