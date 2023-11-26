/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifo_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:05:19 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 23:47:03 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lifo	*lifo_lstnew(int block_size, char quadrant)
{
	t_lifo	*new_node;

	new_node = malloc(sizeof(t_lifo));
	if (new_node == NULL)
		return (NULL);
	new_node->block_size = block_size;
	new_node->quadrant = quadrant;
	new_node->next = NULL;
	return (new_node);
}
