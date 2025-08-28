#include "push_swap.h"

int	apply_rr(t_ctx *ctx, int target, int invert)
{
	if (!invert) // order ab
	{
		while (ctx->sa->num != target && find_place_sb(ctx->sb, target) > 0)
			rr(&ctx->sa, &ctx->sb, 1);
		while (find_place_sb(ctx->sb, target) > 0)
			rb(&ctx->sb, 1);
		while (ctx->sa->num != target)
			ra(&ctx->sa, 1);
		pb(&ctx->sa, &ctx->sb, 1);
	}
	else // order ba
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
	if (!invert) // order ab
	{
		while (ctx->sa->num != target && find_place_sb(ctx->sb, target) > 0)
			rrr(&ctx->sa, &ctx->sb, 1);
		while (find_place_sb(ctx->sb, target) > 0)
			rrb(&ctx->sb, 1);
		while (ctx->sa->num != target)
			rra(&ctx->sa, 1);
		pb(&ctx->sa, &ctx->sb, 1);
	}
	else // order ba
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
	if (!invert) // order ab
	{
		while (ctx->sa->num != target)
			ra(&ctx->sa, 1);
		while (find_place_sb(ctx->sb, target) > 0)
			rrb(&ctx->sb, 1);
		pb(&ctx->sa, &ctx->sb, 1);
	}
	else // order ba
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
	if (!invert) // order ab
	{
		while (ctx->sa->num != target)
			rra(&ctx->sa, 1);
		while (find_place_sb(ctx->sb, target) > 0)
			rb(&ctx->sb, 1);
		pb(&ctx->sa, &ctx->sb, 1);
	}
	else // order ba
	{
		while (ctx->sb->num != target)
			rb(&ctx->sb, 1);
		while (find_place_sa(ctx->sa, target) > 0)
			rra(&ctx->sa, 1);
		pa(&ctx->sa, &ctx->sb, 1);
	}
	return (-1);
}
