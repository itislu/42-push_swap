#include "push_swap.h"

bool	asc(void *value1, void *value2)
{
	return (value1 <= value2);
}

bool	desc(void *value1, void *value2)
{
	return (value1 >= value2);
}

t_list_d	*get_next(t_list_d *node)
{
	return (node->next);
}

t_list_d	*get_prev(t_list_d *node)
{
	return (node->prev);
}
