/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers_compare.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:59:51 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/27 11:26:50 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	asc(t_list_d *node1, t_list_d *node2)
{
	return ((long) node1->content <= (long) node2->content);
}

bool	desc(t_list_d *node1, t_list_d *node2)
{
	return ((long) node1->content >= (long) node2->content);
}

bool	asc_contig(t_list_d *node1, t_list_d *node2)
{
	return (node1->pos_sorted + 1 == node2->pos_sorted);
}

bool	desc_contig(t_list_d *node1, t_list_d *node2)
{
	return (node1->pos_sorted - 1 == node2->pos_sorted);
}
