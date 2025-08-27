#include "push_swap.h"

void	ra(t_stack **head_a, int print)
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
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **head_b, int print)
{
	ra(head_b, 0);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **head_a, t_stack **head_b, int print)
{
	ra(head_a, 0);
	rb(head_b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
