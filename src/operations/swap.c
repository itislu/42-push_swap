/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:47:17 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:39:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_a(t_stacks *stacks)
{
	t_list_d	*new_top_a;

	if (stacks->top_a->next)
	{
		new_top_a = stacks->top_a->next;
		if (new_top_a->next)
			new_top_a->next->prev = stacks->top_a;
		stacks->top_a->next = new_top_a->next;
		stacks->top_a->prev = new_top_a;
		new_top_a->next = stacks->top_a;
		stacks->top_a = new_top_a;
		stacks->top_a->prev = NULL;
		ft_printf("sa\n");
	}
}

void	swap_b(t_stacks *stacks)
{
	t_list_d	*new_top_b;

	if (stacks->top_b->next)
	{
		new_top_b = stacks->top_b->next;
		if (new_top_b->next)
			new_top_b->next->prev = stacks->top_b;
		stacks->top_b->next = new_top_b->next;
		stacks->top_b->prev = new_top_b;
		new_top_b->next = stacks->top_b;
		stacks->top_b = new_top_b;
		stacks->top_b->prev = NULL;
		ft_printf("sb\n");
	}
}

void	swap_both(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
	ft_printf("ss\n");
}
