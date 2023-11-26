/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:16:47 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 15:17:03 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	add_new_task(t_lifo **tasks, int amount, char quadrant)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(amount, quadrant);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(tasks, new_entry);
	return (true);
}
