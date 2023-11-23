/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:43:54 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 15:28:44 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	 check_duplicates(t_list_d *head_a)
{
	t_list_d	*cur;

	cur = head_a;
	while (cur->next)
	{
		if (cur->content == cur->next->content)
			return (1);
		cur = cur->next;
	}
	return (0);
}