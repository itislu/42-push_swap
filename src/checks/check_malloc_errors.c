/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:05:36 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/27 11:08:43 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_malloc_errors(t_stacks *stacks, int input_count)
{
	bool	is_error;

	is_error = false;
	if (!is_n_amount_sorted(stacks->top_a, input_count, asc, get_next))
		is_error = true;
	else if (!is_empty(stacks->top_b, 0, get_next))
		is_error = true;
	ft_lstclear_d(&stacks->top_a, del);
	ft_lstclear_d(&stacks->top_b, del);
	return (is_error);
}
