/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers_traverse.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:59:56 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/26 13:03:10 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_d	*get_next(t_list_d *node)
{
	if (node)
		return (node->next);
	else
		return (node);
}

t_list_d	*get_prev(t_list_d *node)
{
	if (node)
		return (node->prev);
	else
		return (node);
}
