#include "push_swap.h"

long	stack_min(t_stack *stack)
{
	long min;

	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

long	stack_max(t_stack *stack)
{
	long max;

	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	find_stack_index(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->num != nbr)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	find_place_sa(t_stack *sa, int nbr)
{
	t_stack *tmp;
	int		i;

	i = 1;
	if (nbr < sa->num || nbr > stack_last(sa)->num)
		i = 0;
	else if (nbr > stack_max(sa) || nbr < stack_min(sa))
		i = find_stack_index(sa, nbr);
	else
	{
		tmp = sa->next;
		while (tmp && (sa->num < nbr || tmp->num > nbr))
		{
			i++;
			sa = sa->next;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	find_place_sb(t_stack *sb, int nbr)
{
	t_stack *tmp;
	int		i;

	i = 1;
	if (nbr < sb->num || nbr > stack_last(sb)->num)
		i = 0;
	else if (nbr > stack_max(sb) || nbr < stack_min(sb))
		i = find_stack_index(sb, nbr);
	else
	{
		tmp = sb->next;
		while (tmp && (sb->num > nbr || tmp->num < nbr))
		{
			i++;
			sb = sb->next;
			tmp = tmp->next;
		}
	}
	return (i);
}
		
