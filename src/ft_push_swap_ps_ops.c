#include "ft_push_swap.h"

void	ft_push_swap_pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*node;

	if (!head_b || !*head_b)
		return ;
	node = *head_b;
	*head_b = node->next;
	if (*head_b)
		(*head_b)->prev = NULL;
	node->next = *head_a;
	node->prev = NULL;
	if (*head_a)
		(*head_a)->prev = node;
	*head_a = node;
}

void	ft_push_swap_pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*node;

	if (!head_a || !*head_a)
		return ;
	node = *head_a;
	*head_a = node->next;
	if (*head_a)
		(*head_a)->prev = NULL;
	node->next = *head_b;
	node->prev = NULL;
	if (*head_b)
		(*head_b)->prev = node;
	*head_b = node;
}

void	ft_push_swap_sa(t_stack **head_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	
	if (!head_a || !*head_a || !(*head_a)->next)
		return ;
	first = *head_a;
	second = first->next;
	third = second->next;
	*head_a = second;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
}

void	ft_push_swap_sb(t_stack **head_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	
	if (!head_b || !*head_b || !(*head_b)->next)
		return ;
	first = *head_b;
	second = first->next;
	third = second->next;
	*head_b = second;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
}

void	ft_push_swap_ss(t_stack **head_a, t_stack **head_b)
{
	ft_push_swap_sa(head_a);
	ft_push_swap_sb(head_b);
}
