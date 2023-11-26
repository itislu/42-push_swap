/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifo_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:04:18 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 20:39:10 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lifo_lstadd_front(t_lifo **head, t_lifo *new)
{
	if (head != NULL && new != NULL)
	{
		if (*head == NULL)
			*head = new;
		else
		{
			new->next = *head;
			*head = new;
		}
	}
	return ;
}
