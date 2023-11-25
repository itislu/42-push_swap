/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_tasks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:19:08 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 22:41:29 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	add_low_third(t_lifo **tasks, int amounts[], char origin);
bool	add_middle_third(t_lifo **tasks, int amounts[], char origin);
bool	add_high_third(t_lifo **tasks, int amounts[], char origin);

bool	add_amounts_to_tasks(t_lifo **tasks, int amounts[])
{
	char	origin;

	origin = (*tasks)->quadrant;
	lifo_lstclear_n(tasks, 1);
	if (!add_low_third(tasks, amounts, origin))
		return (false);
	if (!add_middle_third(tasks, amounts, origin))
		return (false);
	if (!add_high_third(tasks, amounts, origin))
		return (false);
	return (true);
}

bool	add_low_third(t_lifo **tasks, int amounts[], char origin)
{
	int	quadrant;

	if (origin != BOTTOM_B)
		quadrant = BOTTOM_B;
	else
		quadrant = BOTTOM_A;
	return (add_new_task(tasks, amounts[quadrant], quadrant));
}

bool	add_middle_third(t_lifo **tasks, int amounts[], char origin)
{
	int	quadrant;

	if (origin != TOP_B && origin != TOP_A)
		quadrant = TOP_B;
	else
		quadrant = BOTTOM_A;
	return (add_new_task(tasks, amounts[quadrant], quadrant));
}

bool	add_high_third(t_lifo **tasks, int amounts[], char origin)
{
	int	quadrant;

	if (origin != TOP_A)
		quadrant = TOP_A;
	else
		quadrant = TOP_B;
	return (add_new_task(tasks, amounts[quadrant], quadrant));
}

bool	add_new_task(t_lifo **tasks, int amount, char quadrant)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(amount, quadrant);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(tasks, new_entry);
	return (true);
}
