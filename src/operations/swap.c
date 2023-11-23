/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:47:17 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 16:05:42 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_a(t_heads *heads)
{
	t_list_d	*new_top_a;

	if (heads->top_a && heads->top_a->next)
	{
		new_top_a = heads->top_a->next;
		if (new_top_a->next)
			new_top_a->next->prev = heads->top_a;
		heads->top_a->next = new_top_a->next;
		heads->top_a->prev = new_top_a;
		new_top_a->next = heads->top_a;
		new_top_a->prev = NULL;
		heads->top_a = new_top_a;
		heads->top_a->pos_sorted = 0;
		ft_printf("sa\n");
	}
}

void	swap_b(t_heads *heads)
{
	t_list_d	*new_top_b;

	if (heads->top_b && heads->top_b->next)
	{
		new_top_b = heads->top_b->next;
		if (new_top_b->next)
			new_top_b->next->prev = heads->top_b;
		heads->top_b->next = new_top_b->next;
		heads->top_b->prev = new_top_b;
		new_top_b->next = heads->top_b;
		new_top_b->prev = NULL;
		heads->top_b = new_top_b;
		heads->top_b->pos_sorted = 0;
		ft_printf("sb\n");
	}
}

void	swap_both(t_heads *heads)	// Better convert this *_both in post - although the operations have already been printed out...
{
	swap_a(heads);
	swap_b(heads);
	ft_printf("ss\n");
}
