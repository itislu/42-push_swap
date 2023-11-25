/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_b_to_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:00 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 22:50:42 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_b_to_bottom_a(t_heads *heads, int amounts[])
{
	push_a(heads);
	rotate_a(heads);
	amounts[BOTTOM_A]++;
}

void	top_b_to_bottom_b(t_heads *heads, int amounts[])
{
	rotate_b(heads);
	amounts[BOTTOM_B]++;
}

void	top_b_to_top_a(t_heads *heads, int amounts[])
{
	push_a(heads);
	amounts[TOP_A]++;
}
