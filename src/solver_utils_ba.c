#include "push_swap.c"

int	case_rr_ba(t_stack *sa, t_stack *sb, int nbr)
{
	int	i;

	i = find_place_sa(sa, nbr);
	if (i < find_stack_index(sb, nbr))
		i = find_stack_index(sb, nbr);
	return (i);
}

int	case_rrr_ba(t_stack *sa, t_stack *sb, int nbr)
{
	int i;

	if (find_place_sa(sa, nbr))
		i = stack_size(sa) - find_place_sa(sa, nbr);
	if (find_stack_index(sb, nbr))
	{
		if (i < (stack_size(sb) - find_stack_index(sb, nbr))
			i = stack_size(sb) - find_stack_index(sb, nbr);
	}
	return (i);
}

int	case_rrarb_ba(t_stack *sa, t_stack *sb, int nbr)
{
	int	i;

	i = 0;
	if (find_place_sa(sa, nbr))
		i = stack_size(sa) - find_place_sa(sa, nbr);
	i = find_stack_index(sb, nbr) + i;
}

int	case_rarrb_ba(t_stack *sa, t_stack *sb, int nbr)
{
	int	i;

	i = 0;
	if (find_stack_index(sb, nbr))
		i = stack_size(sb) - find_stack_index(sb, nbr);
	i = find_place_sa(sa, nbr) + i;
}
