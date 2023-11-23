/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_than_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:43:34 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 15:24:51 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_than_integer(t_list_d *head)
{
	t_list_d	*cur;

	/* Check for numbers bigger than an integer */
	cur = head;
	while (cur)
	{
		if ((long) cur->content > INT_MAX || (long) cur->content < INT_MIN)
			return (1);
		cur = cur->next;
	}
	return (0);
}
