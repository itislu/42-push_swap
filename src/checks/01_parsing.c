/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:39:45 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 15:56:21 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_d	*parsing(int argc, char *argv[])
{
	int			i;
	t_list_d	*head_a;
	t_list_d	*new_node;

	head_a = NULL;
	while (--argc > 0)
	{
		i = 0;
		while (argv[argc][i] && ft_isdigit(argv[argc][i]))
			i++;
		if (argv[argc][i] != '\0')
			break ;
		new_node = ft_lstnew_d((void *) ft_atol(argv[argc]));
		if (new_node)
		{
			new_node->pos_origin = argc;
			new_node->pos_sorted = 0;
			ft_lstadd_front_d(&head_a, new_node);
		}
		else
			break ;
	}
	if (argc != 0)
		return (ft_lstclear_d(&head_a), NULL);
	return (head_a);
}
