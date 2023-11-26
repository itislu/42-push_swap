/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:46:26 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/27 00:37:44 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_input_into_stack_a(int argc, char *argv[], t_list_d **top_a);

void	init_stacks(t_stacks *stacks, int argc, char *argv[], int *input_count)
{
	stacks->top_a = NULL;
	*input_count = put_input_into_stack_a(argc, argv, &stacks->top_a);
	stacks->bottom_a = ft_lstlast_d(stacks->top_a);
	stacks->top_b = NULL;
	stacks->bottom_b = NULL;
}

int	put_input_into_stack_a(int argc, char *argv[], t_list_d **top_a)
{
	int			count;
	int			i;
	char		*input;
	t_list_d	*new_node;

	count = 0;
	i = 0;
	while (++i < argc)
	{
		input = ft_strtok(argv[i], WHITESPACE);
		while (input)
		{
			count++;
			new_node = ft_lstnew_d((void *) ft_atol(input));
			if (new_node)
			{
				new_node->pos_origin = count;
				ft_lstadd_back_d(top_a, new_node);
			}
			else
				return (ft_lstclear_d(top_a, del), 0);
			input = ft_strtok(NULL, WHITESPACE);
		}
	}
	return (count);
}
