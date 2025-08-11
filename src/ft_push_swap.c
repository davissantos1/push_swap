/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 23:22:19 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/11 15:45:10 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_strings_to_ints(int argc, char **argv, t_gc *gc)
{
	int	*result;
	int	i;
	int	j;

	i = 0;
	j = 1;
	result = gc_malloc(gc, (argc * sizeof(int)), GC_DEFAULT);
	if (!result)
		return (NULL);
	while (j < argc)
	{
		result[i] = ft_atoi(argv[j]);
		j++;
		i++;
	}
	return (result);
}

int	ft_push_swap(int argc, char **argv)
{
	t_gc	*gc;
	//t_list	*stack_a;
	int		*int_array;

	gc = gc_init();
	if (!gc)
		return (0);
	int_array = ft_strings_to_ints(argc, argv, gc);
	if (!int_array)
		return (0);
	
	return (1);
}
