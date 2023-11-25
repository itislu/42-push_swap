#include "push_swap.h"

bool	is_n_amount_sorted(t_list_d *cur, int n, t_cmp ord, t_trv get_next)
{
	t_list_d	*next;

	if (n == 1)
		return (true);
	while (n > 1)
	{
		next = get_next(cur);
		if (next && !ord(cur->content, next->content))
			break ;
		cur = next;
		n--;
	}
	if (n > 1)
		return (false);
	else
		return (true);
}
