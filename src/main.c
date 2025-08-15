/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:15:12 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/13 14:45:40 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_gc	*gc;
	//int		result;
	char	**parsed;

	gc = gc_init();
	if (!gc || argc < 2)
	{
		gc_free_all(&gc);
		return (1);
	}
	parsed = ft_parse_nbrs(argc, argv);
	gc_addptr(parsed, gc, GC_DEFAULT);
	if (!ft_parse_error(parsed))
	{
		ft_putstr_fd("Error\n", 2);
		gc_free_all(&gc);
		return (1);
	}
	//result = ft_push_swap(parsed);
	//if (!result)
	//	return (1);
	gc_free_all(&gc);
	return (0);
}
