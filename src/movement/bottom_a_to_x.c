/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_a_to_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:00 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 22:21:20 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bottom_a_to_bottom_b(t_heads *heads, int amounts[])
{
	reverse_rotate_a(heads);
	push_b(heads);
	rotate_b(heads);
	amounts[BOTTOM_B]++;
}

void	bottom_a_to_top_a(t_heads *heads, int amounts[])
{
	reverse_rotate_a(heads);
	amounts[TOP_A]++;
}

void	bottom_a_to_top_b(t_heads *heads, int amounts[])
{
	reverse_rotate_a(heads);
	push_b(heads);
	amounts[TOP_B]++;
}
