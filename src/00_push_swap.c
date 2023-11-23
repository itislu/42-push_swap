/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:06 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 23:24:47 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_heads	heads;
	t_lifo	*protocol;

	if (argc < 2)
		return (1);

	/* Parsing */
	heads.top_a = parsing(argc, argv);
	if (!heads.top_a)
		return (ft_printf(ERROR_MSG), 2);
	heads.bottom_a = ft_lstlast_d(heads.top_a);
	heads.top_b = NULL;
	heads.bottom_b = NULL;

	/* INT_MIN/INT_MAX check */
	if (bigger_than_integer(heads.top_a))
		return (ft_lstclear_d(&heads.top_a), ft_printf(ERROR_MSG), 3);

	/* Find the sorted order */
	//find_pos_sorted(heads.top_a, argc - 1, get_next);

	protocol = lifo_lstnew(argc - 1, TOP_A);
	if (!protocol)
		return (ft_lstclear_d(&heads.top_a), ft_printf(ERROR_MSG), 4);

	/* Algorithm */
	if (!sort_block_initial_top_a(&heads, &protocol))
		return (5);
	/* Now follow the protocol */
	while (protocol)
	{
		if (protocol->quadrant == TOP_A)
			sort_block_top_a(&heads, &protocol);
		if (protocol->quadrant == BOTTOM_A)
			sort_block_bottom_a(&heads, &protocol);
		if (protocol->quadrant == TOP_B)
			sort_block_top_b(&heads, &protocol);
		if (protocol->quadrant == BOTTOM_B)
			sort_block_bottom_b(&heads, &protocol);
	}

	/* Check for duplicates in sorted list */
	if (check_duplicates(heads.top_a))
		return (ft_lstclear_d(&heads.top_a), ft_printf(ERROR_MSG), 5);
	return (ft_lstclear_d(&heads.top_a), 0);
}
