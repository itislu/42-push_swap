/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:59:15 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 23:58:04 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

bool	separate_block_initial_top_a(t_heads *heads, int block_size, t_lifo **protocol);

bool	sort_block_initial_top_a(t_heads *heads, t_lifo **protocol)
{
	t_list_d	*cur;

	//heads->bottom_a->next = heads->top_a;
	// Split first third of a
	if (!separate_block_initial_top_a(heads, (*protocol)->block_size, protocol))
		return (ft_lstclear_d(&heads->top_a), ft_lstclear_d(&heads->top_b), lifo_lstclear(protocol), false);
	//heads->bottom_a->next = NULL;
	// Now collect the groups of 2 or 3
	// sort_rest_top_a(heads, protocol);
	// sort_rest_top_b(heads, protocol);
	// sort_rest_bottom_b(heads, protocol);

	/* Reset pos_sorted in case the largest 2 or 3 inputs were already sorted */	//TODO: Can be made general in all the sort_block functions instead of in each operation.
	cur = heads->top_a;
	while (cur)
	{
		cur->pos_sorted = 0;
		cur = cur->next;
	}

	/* amount_left is divisible by 2 now */

	return (true);
}

/* First splitting can be done recursively bc TOP_A is feeding itself only the highest thirds. */
bool	separate_block_initial_top_a(t_heads *heads, int block_size, t_lifo **protocol)
{
	int	i;

	find_pos_sorted(heads->top_a, block_size, get_next);
	/* Base case */
	if(block_size <= 3)	// Would be great to stop earlier, with 4 or 5
	{
		if (!add_single_amount_to_protocol(protocol, block_size, TOP_A))
			return (false);
		return (true);
	}

	i = 0;
	while (i < block_size)
	{
		if (heads->top_a->pos_sorted <= block_size / 3)		//TODO: Add variables to store that result once
		{
			push_b(heads);
			rotate_b(heads);
		}
		else if (heads->top_a->pos_sorted <= block_size / 3 * 2)
		{
			push_b(heads);
		}
		else
		{
			rotate_a(heads);
		}
		i++;
	}
	lifo_lstclear_n(protocol, 1);
	if (!add_amounts_to_protocol_initial_top_a(protocol, block_size))
		return (false);
	return (separate_block_initial_top_a(heads, block_size - block_size / 3 * 2, protocol));
}
