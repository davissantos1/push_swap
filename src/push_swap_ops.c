/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 22:40:08 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/29 22:52:22 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **head_a, t_stack **head_b, int print)
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
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **head_a, t_stack **head_b, int print)
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
	if (print)
		ft_putstr_fd("pb\n", 1);
}

void	sa(t_stack **head_a, int print)
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
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **head_b, int print)
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
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **head_a, t_stack **head_b, int print)
{
	sa(head_a, 0);
	sb(head_b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
