/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:06 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 14:39:06 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int		input_count;
	t_lifo	*tasks;

	if (argc < 2)
		return (1);	// Important: No error message according to subject!

	/* Parsing */
	stacks.top_a = NULL;
	input_count = parsing(argc, argv, &stacks.top_a, 0);
	if (!input_count)
		return (ft_printf(ERROR_MSG), 2);
	stacks.bottom_a = ft_lstlast_d(stacks.top_a);
	stacks.top_b = NULL;
	stacks.bottom_b = NULL;

	/* INT_MIN/INT_MAX check */
	if (bigger_than_integer(stacks.top_a))
		return (ft_lstclear_d(&stacks.top_a), ft_printf(ERROR_MSG), 3);

	/* Check for duplicates in sorted list */
	if (check_duplicates(stacks.top_a))
		return (ft_lstclear_d(&stacks.top_a), ft_printf(ERROR_MSG), 5);

	tasks = lifo_lstnew(input_count, TOP_A);
	if (!tasks)
		return (ft_lstclear_d(&stacks.top_a), ft_printf(ERROR_MSG), 4);

	/* Algorithm */
	if (!separate_stack_a(&stacks, &tasks))
		return (5);
	/* Now follow the tasks */
	while (tasks)
	{
		if (tasks->quadrant == TOP_A)
			sort_block_top_a(&stacks, &tasks);
		else if (tasks->quadrant == TOP_B)
			sort_block_top_b(&stacks, &tasks);
		else if (tasks->quadrant == BOTTOM_B)
			sort_block_bottom_b(&stacks, &tasks);
		else if (tasks->quadrant == BOTTOM_A)
			sort_block_bottom_a(&stacks, &tasks);
	}

	return (ft_lstclear_d(&stacks.top_a), 0);
}
