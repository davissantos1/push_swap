/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:15:12 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/11 16:11:11 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_num(char *num)
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

int	ft_parse_error(int args, char **stack)
{
	int	i;
	int	j;

	i = 1;
	while (i < args)
	{
		j = i + 1;
		if (!ft_is_valid_num(stack[i]))
			return (0);
		while (j < args)
		{
			if (!ft_strncmp(stack[i], stack[j], 12))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	result;

	if (argc < 2)
		return (1);
	if (!ft_parse_error(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	result = ft_push_swap(argc, argv);
	if (!result)
		return (1);
	return (0);
}
