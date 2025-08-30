/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 22:38:10 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/29 22:39:06 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rr(t_ctx *ctx, int target, int invert)
{
	if (!invert)
	{
		while (ctx->sa->num != target && find_place_sb(ctx->sb, target) > 0)
			rr(&ctx->sa, &ctx->sb, 1);
		while (find_place_sb(ctx->sb, target) > 0)
			rb(&ctx->sb, 1);
		while (ctx->sa->num != target)
			ra(&ctx->sa, 1);
		pb(&ctx->sa, &ctx->sb, 1);
	}
	else
	{
		while (ctx->sb->num != target && find_place_sa(ctx->sa, target) > 0)
			rr(&ctx->sa, &ctx->sb, 1);
		while (find_place_sa(ctx->sa, target) > 0)
			ra(&ctx->sa, 1);
		while (ctx->sb->num != target)
			rb(&ctx->sb, 1);
		pa(&ctx->sa, &ctx->sb, 1);
	}
	return (-1);
}	

int	apply_rrr(t_ctx *ctx, int target, int invert)
{
	if (!invert)
	{
		while (ctx->sa->num != target && find_place_sb(ctx->sb, target) > 0)
			rrr(&ctx->sa, &ctx->sb, 1);
		while (find_place_sb(ctx->sb, target) > 0)
			rrb(&ctx->sb, 1);
		while (ctx->sa->num != target)
			rra(&ctx->sa, 1);
		pb(&ctx->sa, &ctx->sb, 1);
	}
	else
	{
		while (ctx->sb->num != target && find_place_sa(ctx->sa, target) > 0)
			rrr(&ctx->sa, &ctx->sb, 1);
		while (find_place_sa(ctx->sa, target) > 0)
			rra(&ctx->sa, 1);
		while (ctx->sb->num != target)
			rrb(&ctx->sb, 1);
		pa(&ctx->sa, &ctx->sb, 1);
	}
	return (-1);
}

int	apply_rarrb(t_ctx *ctx, int target, int invert)
{
	if (!invert)
	{
		while (ctx->sa->num != target)
			ra(&ctx->sa, 1);
		while (find_place_sb(ctx->sb, target) > 0)
			rrb(&ctx->sb, 1);
		pb(&ctx->sa, &ctx->sb, 1);
	}
	else
	{
		while (ctx->sb->num != target)
			rrb(&ctx->sb, 1);
		while (find_place_sa(ctx->sa, target) > 0)
			ra(&ctx->sa, 1);
		pa(&ctx->sa, &ctx->sb, 1);
	}
	return (-1);
}

int	apply_rrarb(t_ctx *ctx, int target, int invert)
{
	if (!invert)
	{
		while (ctx->sa->num != target)
			rra(&ctx->sa, 1);
		while (find_place_sb(ctx->sb, target) > 0)
			rb(&ctx->sb, 1);
		pb(&ctx->sa, &ctx->sb, 1);
	}
	else
	{
		while (ctx->sb->num != target)
			rb(&ctx->sb, 1);
		while (find_place_sa(ctx->sa, target) > 0)
			rra(&ctx->sa, 1);
		pa(&ctx->sa, &ctx->sb, 1);
	}
	return (-1);
}
