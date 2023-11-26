/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_check_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:43:54 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 13:48:56 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	 check_duplicates(t_list_d *head_a)
{
	t_list_d	*cur;
	t_list_d	*to_check;

	to_check = head_a;
	while (to_check)
	{
		cur = to_check->next;
		while (cur)
		{
			if ((long) to_check->content == (long) cur->content)
				return (1);
			cur = cur->next;
		}
		to_check = to_check->next;
	}
	return (0);
}
