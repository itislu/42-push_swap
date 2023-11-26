/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:39:45 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/27 00:37:50 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	parsing(int argc, char *argv[], t_stacks *stacks, int *input_count)
{
	bool	is_error;

	if (check_bad_input(argc, argv))
		return (false);
	init_stacks(stacks, argc, argv, input_count);
	if (!*input_count)
		return (false);
	is_error = false;
	if (check_bigger_than_integer(stacks->top_a))
		is_error = true;
	else if (check_duplicates(stacks->top_a))
		is_error = true;
	if (is_error)
	{
		ft_lstclear_d(&stacks->top_a, del);
		return (false);
	}
	return (true);
}
