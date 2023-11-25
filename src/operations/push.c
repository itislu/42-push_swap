/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:59:17 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 01:05:49 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_a(t_heads *heads)
{
	t_list_d	*new_top_b;

	if (heads->top_b)
	{
		new_top_b = heads->top_b->next;
		if (heads->top_a)
			heads->top_a->prev = heads->top_b;
		else
			heads->bottom_a = heads->top_b;
		heads->top_b->next = heads->top_a;
		heads->top_a = heads->top_b;
		heads->top_b = new_top_b;
		if (heads->top_b)
			heads->top_b->prev = NULL;
		heads->top_a->pos_sorted = 0;
		ft_printf("pa\n");
	}
}

void	push_b(t_heads *heads)
{
	t_list_d	*new_top_a;

	if (heads->top_a)
	{
		new_top_a = heads->top_a->next;
		if (heads->top_b)
			heads->top_b->prev = heads->top_a;
		else
			heads->bottom_b = heads->top_a;
		heads->top_a->next = heads->top_b;
		heads->top_b = heads->top_a;
		heads->top_a = new_top_a;
		if (heads->top_a)
			heads->top_a->prev = NULL;
		heads->top_b->pos_sorted = 0;
		ft_printf("pb\n");
	}
}
