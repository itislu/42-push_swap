/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:59:17 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:39:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_a(t_stacks *stacks)
{
	t_list_d	*new_top_b;

	if (stacks->top_b)
	{
		new_top_b = stacks->top_b->next;
		if (stacks->top_a)
			stacks->top_a->prev = stacks->top_b;
		else
			stacks->bottom_a = stacks->top_b;
		stacks->top_b->next = stacks->top_a;
		stacks->top_a = stacks->top_b;
		stacks->top_b = new_top_b;
		if (stacks->top_b)
			stacks->top_b->prev = NULL;
		ft_printf("pa\n");
	}
}

void	push_b(t_stacks *stacks)
{
	t_list_d	*new_top_a;

	if (stacks->top_a)
	{
		new_top_a = stacks->top_a->next;
		if (stacks->top_b)
			stacks->top_b->prev = stacks->top_a;
		else
			stacks->bottom_b = stacks->top_a;
		stacks->top_a->next = stacks->top_b;
		stacks->top_b = stacks->top_a;
		stacks->top_a = new_top_a;
		if (stacks->top_a)
			stacks->top_a->prev = NULL;
		ft_printf("pb\n");
	}
}
