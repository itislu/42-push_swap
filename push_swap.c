/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:06 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 11:46:29 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	**head_a;
	int		number_amount;

	if (argc < 2)
		return (1);

	/* Parsing */
	head_a = parsing(argc, argv);
	if (!head_a)
		return (ft_lstclear(head_a), ft_printf(ERROR_MSG), 2);

	/* INT_MIN/INT_MAX check */
	if (bigger_than_integer(head_a))
		return (ft_lstclear(head_a), ft_printf(ERROR_MSG), 3);

	/* Find the sorted order */
	find_sorted_positions(head_a, argc);

	number_amount = argc - 1;
	

	/* Check for duplicates in sorted list */
	if (check_duplicates(head_a))
		return (ft_lstclear(head_a), ft_printf(ERROR_MSG), 4);
}