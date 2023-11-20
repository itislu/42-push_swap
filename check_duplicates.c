/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:43:54 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/19 20:46:59 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_list **head)
{
	t_list	*cur;

	cur = *head;
	while (cur->next)
	{
		if (cur->content == cur->next->content)
			return (1);
		cur = cur->next;
	}
	return (0);
}
