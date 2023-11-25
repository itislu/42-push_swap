/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:06 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/25 16:38:38 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_heads	heads;
	int		input_count;
	t_lifo	*tasks;

	if (argc < 2)
		return (1);

	/* Parsing */
	heads.top_a = NULL;
	input_count = parsing(argc, argv, &heads.top_a, 0);
	if (!input_count)
		return (ft_printf(ERROR_MSG), 2);
	heads.bottom_a = ft_lstlast_d(heads.top_a);
	heads.top_b = NULL;
	heads.bottom_b = NULL;

	/* INT_MIN/INT_MAX check */
	if (bigger_than_integer(heads.top_a))
		return (ft_lstclear_d(&heads.top_a), ft_printf(ERROR_MSG), 3);

	tasks = lifo_lstnew(input_count, TOP_A);
	if (!tasks)
		return (ft_lstclear_d(&heads.top_a), ft_printf(ERROR_MSG), 4);

	/* Algorithm */
	if (!separate_stack_a(&heads, &tasks))
		return (5);
	/* Now follow the tasks */
	while (tasks)
	{
		if (tasks->quadrant == TOP_A)
			sort_block_top_a(&heads, &tasks);
		else if (tasks->quadrant == TOP_B)
			sort_block_top_b(&heads, &tasks);
		else if (tasks->quadrant == BOTTOM_B)
			sort_block_bottom_b(&heads, &tasks);
		else if (tasks->quadrant == BOTTOM_A)
			sort_block_bottom_a(&heads, &tasks);
	}

	/* Check for duplicates in sorted list */
	if (check_duplicates(heads.top_a))
		return (ft_lstclear_d(&heads.top_a), ft_printf(ERROR_MSG), 5);
	return (ft_lstclear_d(&heads.top_a), 0);
}
