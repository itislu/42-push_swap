/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bad_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:26:42 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 23:27:00 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_bad_input(int argc, char *argv[])
{
	int	i;

	while (--argc > 0)
	{
		if (!argv[argc])
			return (true);
		i = 0;
		while (argv[argc][i])
		{
			while (ft_isspace(argv[argc][i]))
				i++;
			if (argv[argc][i] == '-' || argv[argc][i] == '+')
				i++;
			if (!ft_isdigit(argv[argc][i]))
				return (true);
			while (ft_isdigit(argv[argc][i]))
				i++;
			if (!ft_isspace(argv[argc][i]) && argv[argc][i] != '\0')
				return (true);
		}
	}
	return (false);
}
