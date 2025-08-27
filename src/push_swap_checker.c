#include "push_swap.h"

int	check_sa(t_stack *sa)
{ 
	t_stack *current;

	current = sa;
	while (current && current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_sb(t_stack *sb)
{ 
	t_stack *current;

	current = sb;
	while (current && current->next)
	{
		if (current->num < current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}
