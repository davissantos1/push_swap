/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:15:24 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/12 21:53:29 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes
# include "../libft/libft.h"
# include <unistd.h>

// Prototypes
char	**ft_parse_nbrs(int argc, char **argv, t_gc *gc);
int		ft_parse_error(char **parsed);
int		ft_is_valid_num(char *num);

#endif
