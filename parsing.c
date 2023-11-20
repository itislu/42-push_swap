/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:39:45 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 11:45:06 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**parsing(int argc, char *argv[])
{
	int		j;
	t_list	**head_a;
	t_list	*new_node;

	while (--argc > 0)
	{
		j = 0;
		while (argv[argc][j] && ft_isdigit(argv[argc][j]))
			j++;
		if (argv[argc][j] != '\0')
			break ;
		new_node = ft_lstnew(ft_atol(argv[argc]));
		if (new_node)
		{
			new_node->pos_origin = argc;
			new_node->pos_sorted = 0;
			ft_lstadd_front(head_a, new_node);
		}
		else
			break ;
	}
	if (argc != 0)
		return (NULL);
	return (head_a);
}
