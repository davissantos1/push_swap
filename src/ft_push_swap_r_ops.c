#include "ft_push_swap.h"

void	ft_push_swap_ra(t_stack **head_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!head_a || !*head_a || !(*head_a)->next)
		return ;
	first = *head_a;
	last = *head_a;
	while (last->next)
		last = last->next;
	*head_a = first->next;
	(*head_a)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ft_push_swap_rb(t_stack **head_b)
{
	ft_push_swap_ra(head_b);
}

void	ft_push_swap_rr(t_stack **head_a, t_stack **head_b)
{
	ft_push_swap_ra(head_a);
	ft_push_swap_rb(head_b);
}
