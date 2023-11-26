/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bigger_than_integer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:43:34 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 23:40:59 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bigger_than_integer(t_list_d *cur)
{
	while (cur)
	{
		if ((long) cur->content > INT_MAX || (long) cur->content < INT_MIN)
			return (1);
		cur = cur->next;
	}
	return (0);
}
