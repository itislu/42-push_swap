/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:10:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:39:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_a(t_stacks *stacks)
{
	t_list_d	*new_top_a;

	if (stacks->top_a->next)
	{
		new_top_a = stacks->top_a->next;
		stacks->bottom_a->next = stacks->top_a;
		stacks->top_a->prev = stacks->bottom_a;
		stacks->bottom_a = stacks->top_a;
		stacks->bottom_a->next = NULL;
		stacks->top_a = new_top_a;
		stacks->top_a->prev = NULL;
		ft_printf("ra\n");
	}
}

void	rotate_b(t_stacks *stacks)
{
	t_list_d	*new_top_b;

	if (stacks->top_b->next)
	{
		new_top_b = stacks->top_b->next;
		stacks->bottom_b->next = stacks->top_b;
		stacks->top_b->prev = stacks->bottom_b;
		stacks->bottom_b = stacks->top_b;
		stacks->bottom_b->next = NULL;
		stacks->top_b = new_top_b;
		stacks->top_b->prev = NULL;
		ft_printf("rb\n");
	}
}

void	rotate_both(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
	ft_printf("rr\n");
}
