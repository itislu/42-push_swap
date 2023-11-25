/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:59:17 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 00:24:03 by ldulling         ###   ########.fr       */
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
		ft_printf("pb\n");
	}
}
