/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:06 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/27 00:47:04 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_stacks *stacks, t_lifo **tasks);

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	int			input_count;
	t_lifo		*tasks;

	if (argc < 2)
		return (1);
	if (!parsing(argc, argv, &stacks, &input_count))
	{
		ft_printf(ERROR_MSG);
		return (2);
	}
	tasks = lifo_lstnew(input_count, TOP_A);
	if (!tasks)
	{
		ft_lstclear_d(&stacks.top_a, del);
		ft_printf(ERROR_MSG);
		return (3);
	}
	algorithm(&stacks, &tasks);
	if (check_malloc_errors(&stacks, input_count))
		return (4);
	else
		return (0);
}

void	algorithm(t_stacks *stacks, t_lifo **tasks)
{
	separate_stack_a(stacks, tasks);
	while (*tasks)
	{
		if ((*tasks)->quadrant == TOP_A)
			sort_block_top_a(stacks, tasks);
		else if ((*tasks)->quadrant == TOP_B)
			sort_block_top_b(stacks, tasks);
		else if ((*tasks)->quadrant == BOTTOM_B)
			sort_block_bottom_b(stacks, tasks);
		else if ((*tasks)->quadrant == BOTTOM_A)
			sort_block_bottom_a(stacks, tasks);
	}
}
