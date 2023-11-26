/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_bottom_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:49:06 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:49:06 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_bottom_b(t_stacks *stacks);

void	sort_rest_bottom_b(t_stacks *stacks, t_lifo **tasks)
{
	if (is_n_amount_sorted(stacks->bottom_b, (*tasks)->block_size, desc, get_prev))
	{
		while ((*tasks)->block_size-- > 0)
		{
			reverse_rotate_b(stacks);
			push_a(stacks);
		}
	}
	else
	{
		if ((*tasks)->block_size == 2)
		{
			reverse_rotate_b(stacks);
			reverse_rotate_b(stacks);
			push_a(stacks);
			push_a(stacks);
		}
		else
			sort_three_bottom_b(stacks);
	}
	lifo_lstclear_n(tasks, 1);
}

void	sort_three_bottom_b(t_stacks *stacks)
{
	if(is_n_amount_sorted(stacks->bottom_b, 3, asc, get_prev))
	{
		reverse_rotate_b(stacks);
		reverse_rotate_b(stacks);
		reverse_rotate_b(stacks);
		push_a(stacks);
		push_a(stacks);
		push_a(stacks);
	}
	else
	{
		reverse_rotate_b(stacks);
		reverse_rotate_b(stacks);
		if (!is_n_amount_sorted(stacks->top_b, 2, desc, get_next))
			swap_b(stacks);
		push_a(stacks);
		// Check if bottom is higher than top
		reverse_rotate_b(stacks);
		// Else push and then rotate
		if (!is_n_amount_sorted(stacks->top_b, 2, desc, get_next))
			swap_b(stacks);
		push_a(stacks);
		if (!is_n_amount_sorted(stacks->top_a, 2, asc, get_next))
			swap_a(stacks);
		push_a(stacks);
	}
}
