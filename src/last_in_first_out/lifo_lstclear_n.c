/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifo_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:04:22 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 20:39:14 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lifo_lstclear_n(t_lifo **head, int n)
{
	t_lifo	*cur;

	if (head != NULL)
	{
		while (*head != NULL && n-- > 0)
		{
			cur = *head;
			*head = (*head)->next;
			free(cur);
		}
	}
	return ;
}
