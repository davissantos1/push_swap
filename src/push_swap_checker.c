/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 22:39:59 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/29 22:47:59 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sa(t_stack *sa)
{
	t_stack	*current;

	current = sa;
	while (current && current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_sb(t_stack *sb)
{
	t_stack	*current;

	current = sb;
	while (current && current->next)
	{
		if (current->num < current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}
