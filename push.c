/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:59:17 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 12:09:08 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_list **head_to, t_list **head_from)
{
	t_list	*from_second;

	if (*head_from)
	{
		from_second = (*head_from)->next;
		(*head_from)->next = *head_to;
		*head_to = *head_from;
		*head_from = from_second;
	}
}
