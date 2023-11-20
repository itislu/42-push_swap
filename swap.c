/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:47:17 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 12:06:44 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list	**head)
{
	t_list	*second;

	if (*head && (*head)->next)
	{
		second = (*head)->next;
		(*head)->next = second->next;
		second->next = *head;
		*head = second;
	}
}

void	swap_both(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
}
