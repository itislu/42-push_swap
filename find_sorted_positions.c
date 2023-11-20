/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sorted_positions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:07:32 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 11:45:28 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_sorted_positions(t_list **head_a, int argc)
{
	t_list	*cur;
	t_list	*highest;
	int		pos_sorted;

	pos_sorted = argc - 1;
	cur = *head_a;
	while (argc > 0)
	{
		while (cur->pos_sorted != 0)
			cur = cur->next;
		highest = cur;
		cur = cur->next;
		while (cur)
		{
			if (cur->content >= highest->content)
				highest = cur;
			cur = cur->next;
			while (cur && cur->pos_sorted != 0)
				cur = cur->next;
		}
		highest->pos_sorted = argc;
		argc--;
	}
}

int (*cmp)(int, int)
{

}
int ascending(int a, int b)	//watch out if 0 or 1 means true
{
	return (a <= b);
}
