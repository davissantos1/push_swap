/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:21:18 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/12 22:42:13 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	**ft_parse_nbrs(int argc, char **argv, t_gc *gc)
{
	char	**parsed;
	char	**splitted;
	char	**temp;
	int		i;
	
	i = 1;
	parsed = ft_calloc(1, sizeof(char *));
	if (!parsed)
		return (NULL);
	while (i < argc)
	{
		temp = parsed;
		splitted = ft_split(argv[i], ' ');
		parsed = ft_mtxjoin(parsed, splitted);
		ft_mtxfree(temp);
		ft_mtxfree(splitted);
		i++;
	}
	gc_addptr(parsed, gc, GC_DEFAULT);
	return (parsed);
}

int	ft_parse_error(char **parsed)
{
	int	i;
	int	j;

	i = 1;
	while (parsed[i])
	{
		j = i + 1;
		if (!ft_is_valid_num(parsed[i]))
			return (0);
		while (parsed[i][j])
		{
			if (!ft_strncmp(parsed[i], parsed[j], 12))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
