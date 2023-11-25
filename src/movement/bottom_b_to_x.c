/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_b_to_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:00 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 22:21:27 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bottom_b_to_bottom_a(t_heads *heads, int amounts[])
{
	reverse_rotate_b(heads);
	push_a(heads);
	rotate_a(heads);
	amounts[BOTTOM_A]++;
}

void	bottom_b_to_top_a(t_heads *heads, int amounts[])
{
	reverse_rotate_b(heads);
	push_a(heads);
	amounts[TOP_A]++;
}

void	bottom_b_to_top_b(t_heads *heads, int amounts[])
{
	reverse_rotate_b(heads);
	amounts[TOP_B]++;
}
