/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigger_than_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:43:34 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 11:45:22 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_than_integer(t_list **head_a)
{
	t_list	*cur;
	int		i;

	/* Check for numbers bigger than an integer */
	cur = *head_a;
	while (cur)
	{
		if (cur->content > INT_MAX || cur->content < INT_MIN)
			return (1);
		cur = cur->next;
	}
	return (0);
}
