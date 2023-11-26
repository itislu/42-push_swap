/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:10:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:39:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_rotate_a(t_stacks *stacks)
{
	t_list_d	*new_bottom_a;

	if (stacks->bottom_a->prev)
	{
		new_bottom_a = stacks->bottom_a->prev;
		stacks->top_a->prev = stacks->bottom_a;
		stacks->bottom_a->next = stacks->top_a;
		stacks->top_a = stacks->bottom_a;
		stacks->top_a->prev = NULL;
		stacks->bottom_a = new_bottom_a;
		stacks->bottom_a->next = NULL;
		ft_printf("rra\n");
	}
}

void	reverse_rotate_b(t_stacks *stacks)
{
	t_list_d	*new_bottom_b;

	if (stacks->bottom_b->prev)
	{
		new_bottom_b = stacks->bottom_b->prev;
		stacks->top_b->prev = stacks->bottom_b;
		stacks->bottom_b->next = stacks->top_b;
		stacks->top_b = stacks->bottom_b;
		stacks->top_b->prev = NULL;
		stacks->bottom_b = new_bottom_b;
		stacks->bottom_b->next = NULL;
		ft_printf("rrb\n");
	}
}

void	reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
	ft_printf("rrr\n");
}
