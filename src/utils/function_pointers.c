#include "push_swap.h"

bool	asc(long value1, long value2)
{
	return (value1 <= value2);
}

bool	desc(long value1, long value2)
{
	return (value1 >= value2);
}

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
