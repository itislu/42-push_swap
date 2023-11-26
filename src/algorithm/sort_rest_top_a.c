/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_top_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:49:03 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 18:31:58 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_top_a(t_stacks *stacks);

void	sort_rest_top_a(t_stacks *stacks, t_lifo **tasks)
{
	if (!is_n_amount_sorted(stacks->top_a, (*tasks)->block_size, asc, get_next))
	{
		if ((*tasks)->block_size == 2)
			swap_a(stacks);
		else
			sort_three_top_a(stacks);
	}
	lifo_lstclear_n(tasks, 1);
}

void	sort_three_top_a(t_stacks *stacks)
{
	if (stacks->top_a->next == stacks->bottom_a->prev)
	{
		if (stacks->top_a->pos_sorted == 3)
			rotate_a(stacks);
		else if (stacks->top_a->next->pos_sorted == 3)
			reverse_rotate_a(stacks);
	}
	if (!is_n_amount_sorted(stacks->top_a, 2, asc, get_next))
		swap_a(stacks);
	if (!is_n_amount_sorted(stacks->top_a->next, 2, asc, get_next))
	{
		push_b(stacks);
		swap_a(stacks);
		push_a(stacks);
		if (!is_n_amount_sorted(stacks->top_a, 2, asc, get_next))
			swap_a(stacks);
	}
}
