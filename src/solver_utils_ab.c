#include "push_swap.c"

int	case_rr_ab(t_stack *sa, t_stack *sb, int nbr)
{
	int	i;

	i = find_place_sb(sb, nbr);
	if (i < find_stack_index(sa, nbr))
		i = find_stack_index(sa, nbr);
	return (i);
}

int	case_rrr_ab(t_stack *sa, t_stack *sb, int nbr)
{
	int i;

	if (find_place_sb(sb, nbr))
		i = stack_size(sb) - find_place_sb(sb, nbr);
	if (find_stack_index(sa, nbr))
	{
		if (i < (stack_size(sa) - find_stack_index(sa, nbr))
			i = stack_size(sa) - find_stack_index(sa,nbr);
	}
	return (i);
}

int	case_rrarb_ab(t_stack *sa, t_stack *sb, int nbr)
{
	int	i;

	i = 0;
	if (find_stack_index(sa, nbr))
		i = stack_size(sa) - find_stack_index(sa, nbr);
	i = find_place_sb(sb, nbr) + i;
}

int	case_rarrb_ab(t_stack *sa, t_stack *sb, int nbr)
{
	int	i;

	i = 0;
	if (find_place_sb(sb, nbr))
		i = stack_size(sb) - find_place_sb(sb, nbr);
	i = find_stack_index(sa, nbr) + i;
}
