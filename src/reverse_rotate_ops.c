#include "push_swap.h"

void	rra(t_stack **head_a, int print)
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
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **head_b, int print)
{
	rra(head_b, 0);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **head_a, t_stack **head_b, int print)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
