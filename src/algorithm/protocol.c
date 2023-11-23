#include "push_swap.h"

bool	add_amounts_to_protocol_initial_top_a(t_lifo **protocol, int block_size)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(block_size / 3, BOTTOM_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);

	new_entry = lifo_lstnew(block_size / 3, TOP_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);

	return (true);
}

bool	add_amounts_to_protocol_top_a(t_lifo **protocol, int block_size)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(block_size / 3, BOTTOM_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	new_entry = lifo_lstnew(block_size / 3, BOTTOM_A);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	new_entry = lifo_lstnew(block_size - block_size / 3 * 2, TOP_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	return (true);
}

bool	add_amounts_to_protocol_top_b(t_lifo **protocol, int block_size)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(block_size / 3, BOTTOM_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	new_entry = lifo_lstnew(block_size / 3, BOTTOM_A);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	new_entry = lifo_lstnew(block_size - block_size / 3 * 2, TOP_A);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	return (true);
}

bool	add_amounts_to_protocol_bottom_a(t_lifo **protocol, int block_size)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(block_size / 3, BOTTOM_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	new_entry = lifo_lstnew(block_size / 3, TOP_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	new_entry = lifo_lstnew(block_size - block_size / 3 * 2, TOP_A);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	return (true);
}

bool	add_amounts_to_protocol_bottom_b(t_lifo **protocol, int block_size)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(block_size / 3, BOTTOM_A);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	new_entry = lifo_lstnew(block_size / 3, TOP_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	new_entry = lifo_lstnew(block_size - block_size / 3 * 2, TOP_A);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	return (true);
}

bool	add_amounts_to_protocol_general(t_lifo **protocol, int block_size, char coming_from)
{
	t_lifo	*new_entry;

	if (coming_from != BOTTOM_B)
		new_entry = lifo_lstnew(block_size / 3, BOTTOM_B);
	else
		new_entry = lifo_lstnew(block_size / 3, BOTTOM_A);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	if (coming_from != TOP_B)
		new_entry = lifo_lstnew(block_size / 3, TOP_B);
	else
		new_entry = lifo_lstnew(block_size / 3, BOTTOM_A);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	if (coming_from != TOP_A)
		new_entry = lifo_lstnew(block_size - block_size / 3 * 2, TOP_A);
	else
		new_entry = lifo_lstnew(block_size - block_size / 3 * 2, TOP_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	return (true);
}

bool	add_single_amount_to_protocol(t_lifo **protocol, int block_size, char quadrant)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(block_size, quadrant);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(protocol, new_entry);
	return (true);
}
