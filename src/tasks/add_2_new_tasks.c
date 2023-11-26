/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_2_new_tasks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:16:47 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 15:29:07 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	add_2_new_tasks(t_lifo **tasks, int amounts[], int qu1, int qu2)
{
	if (!add_new_task(tasks, amounts[qu1], qu1))
		return (false);
	if (!add_new_task(tasks, amounts[qu2], qu2))
		return (false);
	return (true);
}
