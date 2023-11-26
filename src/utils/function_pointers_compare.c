/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers_compare.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:59:51 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 13:03:09 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	asc(long value1, long value2)
{
	return (value1 <= value2);
}

bool	desc(long value1, long value2)
{
	return (value1 >= value2);
}

bool	asc_contig(long value1, long value2)
{
	return (value1 + 1 == value2);
}

bool	desc_contig(long value1, long value2)
{
	return (value1 - 1 == value2);
}
