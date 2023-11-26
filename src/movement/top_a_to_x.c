/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_a_to_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:56:00 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:39:01 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_a_to_bottom_a(t_stacks *stacks, int amounts[])
{
	rotate_a(stacks);
	amounts[BOTTOM_A]++;
}

void	top_a_to_bottom_b(t_stacks *stacks, int amounts[])
{
	push_b(stacks);
	rotate_b(stacks);
	amounts[BOTTOM_B]++;
}

void	top_a_to_top_b(t_stacks *stacks, int amounts[])
{
	push_b(stacks);
	amounts[TOP_B]++;
}
