/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:10:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 16:07:18 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	reverse_rotate_a(t_heads *heads)
{
	t_list_d	*new_bottom_a;

	if (heads->bottom_a && heads->bottom_a->prev)
	{
		new_bottom_a = heads->bottom_a->prev;
		if (heads->top_a)
			heads->top_a->prev = heads->bottom_a;
		heads->bottom_a->next = heads->top_a;
		heads->bottom_a->prev = NULL;
		new_bottom_a->next = NULL;
		heads->top_a = heads->bottom_a;
		heads->bottom_a = new_bottom_a;
		heads->top_a->pos_sorted = 0;
		ft_printf("rra\n");	//TODO: Test for error detection if putting it outside of the if makes a difference
	}
}

void	reverse_rotate_b(t_heads *heads)
{
	t_list_d	*new_bottom_b;

	if (heads->bottom_b && heads->bottom_b->prev)
	{
		new_bottom_b = heads->bottom_b->prev;
		if (heads->top_b)
			heads->top_b->prev = heads->bottom_b;
		heads->bottom_b->next = heads->top_b;
		heads->bottom_b->prev = NULL;
		new_bottom_b->next = NULL;
		heads->top_b = heads->bottom_b;
		heads->bottom_b = new_bottom_b;
		heads->top_b->pos_sorted = 0;
		ft_printf("rrb\n");
	}
}

void	reverse_rotate_both(t_heads *heads)	// Better convert this _both's one in post - although the operations have already been printed out - although the operations have already been printed out
{
	reverse_rotate_a(heads);
	reverse_rotate_b(heads);
	ft_printf("rrr\n");
}
