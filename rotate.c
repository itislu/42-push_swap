/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:10:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 12:36:36 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_list **head)
{
	t_list	*second;
	t_list	*tail;

	if (*head && (*head)->next)
	{
		second = (*head)->next;
		tail = ft_lstlast(*head);
		tail->next = *head;
		(*head)->next = NULL;
		*head = second;
	}
}

void	rotate_both(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	reverse_rotate(t_list **head)
{
	t_list	*second_last;
	t_list	*tail;

	if (*head && (*head)->next)
	{
		second_last = ft_lstsecondlast(*head);
		tail = second_last->next;
		tail->next = *head;
		second_last->next = NULL;
		*head = tail;
	}
}

void	reverse_rotate_both(t_list **head_a, t_list **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
}
