/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 23:22:19 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/11 17:05:26 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_push_swap(char **parsed, t_gc *gc)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*int_array;
	int		size;

	size = ft_mtxlen(parsed);
	int_array = ft_strings_to_ints(parsed, gc);
	if (!int_array)
		return (0);
	stack_a = gc_malloc(sizeof(t_stack), gc, GC_DEFAULT);
	if (!stack_a)
		return (0);
	stack_b = gc_malloc(sizeof(t_stack), gc, GC_DEFAULT);
	if (!stack_b)
		return (0);
	stack_a = ft_stack_init(stack_a, int_array, size, gc);
	ft_push_swap_solver(stack_a, stack_b, gc);
	return (1);
}
