/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:39:45 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 00:21:15 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_validity(int argc, char *argv[]);

int	parsing(int argc, char *argv[], t_list_d **top_a, int count)
{
	int			i;
	char		*input;
	t_list_d	*new_node;

	if (!check_validity(argc, argv))
		return (0);
	i = 0;
	while (++i < argc)
	{
		input = ft_strtok(argv[i], " \f\n\r\t\v");
		while (input)
		{
			new_node = ft_lstnew_d((void *) ft_atol(input));
			if (new_node)
			{
				new_node->pos_origin = ++count;
				new_node->pos_sorted = 0;
				ft_lstadd_back_d(top_a, new_node);
			}
			else
				return (ft_lstclear_d(top_a), 0);
			input = ft_strtok(NULL, " \f\n\r\t\v");
		}
	}
	return (count);
}

bool	check_validity(int argc, char *argv[])
{
	int	i;

	while (--argc > 0)
	{
		if (!argv[argc])
			return (false);
		i = 0;
		while (argv[argc][i])
		{
			while (ft_isspace(argv[argc][i]))
				i++;
			if (argv[argc][i] == '-' || argv[argc][i] == '+')
				i++;
			if (!ft_isdigit(argv[argc][i]))
				return (false);
			while (ft_isdigit(argv[argc][i]))
				i++;
			if (!ft_isspace(argv[argc][i]) && argv[argc][i] != '\0')
				return (false);
		}
	}
	return (true);
}
