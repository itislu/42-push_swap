/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:17:02 by ldulling          #+#    #+#             */
/*   Updated: 2023/11/20 12:38:19 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_MSG "Error\n"

# include "libft.h"
# include "ft_printf.h"

t_list	**parsing(int argc, char *argv[]);
int		bigger_than_integer(t_list **head);
void	find_sorted_positions(t_list **head, int argc);

/* Operations */
void	swap(t_list **head);
void	swap_both(t_list **head_a, t_list **head_b);
void	push(t_list **head_to, t_list **head_from);
void	rotate(t_list **head);
void	rotate_both(t_list **head_a, t_list **head_b);
void	reverse_rotate(t_list **head);
void	reverse_rotate_both(t_list **head_a, t_list **head_b);

//TODO
int		check_duplicates(t_list **head);
