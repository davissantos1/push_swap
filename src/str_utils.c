/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:24:45 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/12 21:54:06 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int nbr, int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}
	
int	is_valid_num(char *num)
{
	long	nbr;
	int		i;

	i = 0;
	while (num[i])
	{
		if (i == 0 && (num[i] == '-' || num[i] == '+'))
			i++;
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	nbr = ft_atol(num);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

int	*strings_to_ints(char **parsed, t_gc *gc)
{
	int	*result;
	int	size;
	int	i;

	i = 0;
	size = ft_mtxlen(parsed);
	result = gc_malloc((size * sizeof(int)), gc, GC_DEFAULT);
	if (!result)
		return (NULL);
	while (parsed[i])
	{
		result[i] = ft_atoi(parsed[i]);
		i++;
	}
	return (result);
}

char	**parse_nbrs(int argc, char **argv)
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
	return (parsed);
}

int	parse_error(char **parsed)
{
	int	i;
	int	j;

	i = 0;
	while (parsed[i])
	{
		j = i + 1;
		if (!ft_is_valid_num(parsed[i]))
			return (0);
		while (parsed[j])
		{
			if (!ft_strncmp(parsed[i], parsed[j], 12))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
