#include "push_swap.h"

bool	add_amounts_to_tasks_initial_top_a(t_lifo **tasks, int block_size)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(block_size / 3, BOTTOM_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(tasks, new_entry);

	new_entry = lifo_lstnew(block_size / 3, TOP_B);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(tasks, new_entry);

	return (true);
}

bool	add_amounts_to_tasks(t_lifo **tasks, int block_size)
{
	t_lifo	*new_entry;
	char	quadrant;

	quadrant = (*tasks)->quadrant;
	lifo_lstclear_n(tasks, 1);
	new_entry = lifo_lstnew(block_size / 3, BOTTOM_B);
	if (!new_entry)
		return (false);
	if (quadrant == BOTTOM_B)
		new_entry->quadrant = BOTTOM_A;
	lifo_lstadd_front(tasks, new_entry);
	new_entry = lifo_lstnew(block_size / 3, TOP_B);
	if (!new_entry)
		return (false);
	if (quadrant == TOP_B || quadrant == TOP_A)
		new_entry->quadrant = BOTTOM_A;
	lifo_lstadd_front(tasks, new_entry);
	new_entry = lifo_lstnew(block_size - block_size / 3 * 2, TOP_A);
	if (quadrant == TOP_A)
		new_entry->quadrant = TOP_B;
	if (!new_entry)
		return (false);
	lifo_lstadd_front(tasks, new_entry);
	return (true);
}

bool	add_single_amount_to_tasks(t_lifo **tasks, int block_size, char quadrant)
{
	t_lifo	*new_entry;

	new_entry = lifo_lstnew(block_size, quadrant);
	if (!new_entry)
		return (false);
	lifo_lstadd_front(tasks, new_entry);
	return (true);
}
