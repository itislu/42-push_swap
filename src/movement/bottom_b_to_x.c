/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_b_to_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:00 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:39:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bottom_b_to_bottom_a(t_stacks *stacks, int amounts[])
{
	reverse_rotate_b(stacks);
	push_a(stacks);
	rotate_a(stacks);
	amounts[BOTTOM_A]++;
}

void	bottom_b_to_top_a(t_stacks *stacks, int amounts[])
{
	reverse_rotate_b(stacks);
	push_a(stacks);
	amounts[TOP_A]++;
}

void	bottom_b_to_top_b(t_stacks *stacks, int amounts[])
{
	reverse_rotate_b(stacks);
	amounts[TOP_B]++;
}
