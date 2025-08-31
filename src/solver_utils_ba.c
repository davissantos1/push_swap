/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 22:41:16 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/30 21:59:04 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation_count_ba(t_ctx *ctx)
{
	int		i;
	t_stack	*tmp;

	tmp = ctx->sb;
	i = case_rr_ba(ctx, ctx->sb->num);
	while (tmp)
	{
		if (i > case_rr_ba(ctx, tmp->num))
			i = case_rr_ba(ctx, tmp->num);
		if (i > case_rrr_ba(ctx, tmp->num))
			i = case_rrr_ba(ctx, tmp->num);
		if (i > case_rrarb_ba(ctx, tmp->num))
			i = case_rrarb_ba(ctx, tmp->num);
		if (i > case_rarrb_ba(ctx, tmp->num))
			i = case_rarrb_ba(ctx, tmp->num);
		tmp = tmp->next;
	}
	return (i);
}

int	case_rr_ba(t_ctx *ctx, int nbr)
{
	int	i;

	i = find_place_sa(ctx->sa, nbr);
	if (i < find_stack_index(ctx->sb, nbr))
		i = find_stack_index(ctx->sb, nbr);
	return (i);
}

int	case_rrr_ba(t_ctx *ctx, int nbr)
{
	int	i;

	i = 0;
	if (find_place_sa(ctx->sa, nbr))
		i = stack_size(ctx->sa) - find_place_sa(ctx->sa, nbr);
	if (find_stack_index(ctx->sb, nbr))
	{
		if (i < (stack_size(ctx->sb) - find_stack_index(ctx->sb, nbr)))
			i = stack_size(ctx->sb) - find_stack_index(ctx->sb, nbr);
	}
	return (i);
}

int	case_rrarb_ba(t_ctx *ctx, int nbr)
{
	int	i;

	i = 0;
	if (find_place_sa(ctx->sa, nbr))
		i = stack_size(ctx->sa) - find_place_sa(ctx->sa, nbr);
	i = find_stack_index(ctx->sb, nbr) + i;
	return (i);
}

int	case_rarrb_ba(t_ctx *ctx, int nbr)
{
	int	i;

	i = 0;
	if (find_stack_index(ctx->sb, nbr))
		i = stack_size(ctx->sb) - find_stack_index(ctx->sb, nbr);
	i = find_place_sa(ctx->sa, nbr) + i;
	return (i);
}
