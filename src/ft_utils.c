/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:24:45 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/12 21:54:06 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
