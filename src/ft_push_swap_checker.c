#include "ft_push_swap.h"

int	ft_push_swap_check_sa(t_stack *sa)
{ 
	t_stack *current;
	t_stack *compare;

	current = sa;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->num > compare->num)
				return (0);
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_push_swap_check_sb(t_stack *sb)
{ 
	t_stack *current;
	t_stack *compare;

	current = sb;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->num < compare->num)
				return (0);
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}
