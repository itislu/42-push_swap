/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:10:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 01:40:46 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_rotate_a(t_heads *heads)
{
	t_list_d	*new_bottom_a;

	if (heads->bottom_a->prev)
	{
		new_bottom_a = heads->bottom_a->prev;
		heads->top_a->prev = heads->bottom_a;
		heads->bottom_a->next = heads->top_a;
		heads->top_a = heads->bottom_a;
		heads->top_a->prev = NULL;
		heads->bottom_a = new_bottom_a;
		heads->bottom_a->next = NULL;
		ft_printf("rra\n");
	}
	heads->top_a->pos_sorted = 0;
}

void	reverse_rotate_b(t_heads *heads)
{
	t_list_d	*new_bottom_b;

	if (heads->bottom_b->prev)
	{
		new_bottom_b = heads->bottom_b->prev;
		heads->top_b->prev = heads->bottom_b;
		heads->bottom_b->next = heads->top_b;
		heads->top_b = heads->bottom_b;
		heads->top_b->prev = NULL;
		heads->bottom_b = new_bottom_b;
		heads->bottom_b->next = NULL;
		ft_printf("rrb\n");
	}
	heads->top_b->pos_sorted = 0;
}

void	reverse_rotate_both(t_heads *heads)
{
	reverse_rotate_a(heads);
	reverse_rotate_b(heads);
	ft_printf("rrr\n");
}
