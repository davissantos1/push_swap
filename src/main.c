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
	char	**parsed;

	if (argc < 2)
		return (1);
	gc = gc_init();
	parsed = ft_parse_nbrs(argc, argv);
	if (!gc || !gc_addmtx(parsed, gc, GC_DEFAULT))
	{
		gc = gc_free_all(gc);
		return (1);
	}
	if (!ft_parse_error(parsed))
	{
		ft_putstr_fd("Error\n", 2);
		gc = gc_free_all(gc);
		return (1);
	}
	if (!ft_push_swap(parsed, gc))
	{
		gc = gc_free_all(gc);
		return (1);
	}
	gc = gc_free_all(gc);
	return (0);
}
