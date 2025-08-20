#include "ft_push_swap.h"

void	ft_push_swap_rra(t_stack **head_a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!head_a || !*head_a || !(*head_a)->next)
		return ;
	last = *head_a;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *head_a;
	(*head_a)->prev = last;
	*head_a = last;
}

void	ft_push_swap_rrb(t_stack **head_b)
{
	ft_push_swap_rra(head_b);
}

void	ft_push_swap_rrr(t_stack **head_a, t_stack **head_b)
{
	ft_push_swap_rra(head_a);
	ft_push_swap_rrb(head_b);
}
