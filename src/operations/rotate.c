/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:10:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 01:40:52 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_a(t_heads *heads)
{
	t_list_d	*new_top_a;

	if (heads->top_a->next)
	{
		new_top_a = heads->top_a->next;
		heads->bottom_a->next = heads->top_a;
		heads->top_a->prev = heads->bottom_a;
		heads->bottom_a = heads->top_a;
		heads->bottom_a->next = NULL;
		heads->top_a = new_top_a;
		heads->top_a->prev = NULL;
		ft_printf("ra\n");
	}
	heads->bottom_a->pos_sorted = 0;
}

void	rotate_b(t_heads *heads)
{
	t_list_d	*new_top_b;

	if (heads->top_b->next)
	{
		new_top_b = heads->top_b->next;
		heads->bottom_b->next = heads->top_b;
		heads->top_b->prev = heads->bottom_b;
		heads->bottom_b = heads->top_b;
		heads->bottom_b->next = NULL;
		heads->top_b = new_top_b;
		heads->top_b->prev = NULL;
		ft_printf("rb\n");
	}
	heads->bottom_b->pos_sorted = 0;
}

void	rotate_both(t_heads *heads)
{
	rotate_a(heads);
	rotate_b(heads);
	ft_printf("rr\n");
}
