#include "push_swap.h"

int	rotation_count_ab(t_ctx *ctx)
{
	int	i;
	t_stack *tmp;

	tmp = ctx->sa;
	i = case_rr_ab(ctx, ctx->sa->num);
	while (tmp)
	{
		if (i > case_rr_ab(ctx, tmp->num))
			i = case_rr_ab(ctx, tmp->num);
		if (i > case_rrr_ab(ctx, tmp->num))
			i = case_rrr_ab(ctx, tmp->num);
		if (i > case_rrarb_ab(ctx, tmp->num))
			i = case_rrarb_ab(ctx, tmp->num);
		if (i > case_rarrb_ab(ctx, tmp->num))
			i = case_rarrb_ab(ctx, tmp->num);
		tmp = tmp->next;
	}
	return (i);
}

int	case_rr_ab(t_ctx *ctx, int nbr)
{
	int	i;

	i = find_place_sb(ctx->sb, nbr);
	if (i < find_stack_index(ctx->sa, nbr))
		i = find_stack_index(ctx->sa, nbr);
	return (i);
}

int	case_rrr_ab(t_ctx *ctx, int nbr)
{
	int i;

	if (find_place_sb(ctx->sb, nbr))
		i = stack_size(ctx->sb) - find_place_sb(ctx->sb, nbr);
	if (find_stack_index(ctx->sa, nbr))
	{
		if (i < (stack_size(ctx->sa) - find_stack_index(ctx->sa, nbr)))
			i = stack_size(ctx->sa) - find_stack_index(ctx->sa,nbr);
	}
	return (i);
}

int	case_rrarb_ab(t_ctx *ctx, int nbr)
{
	int	i;

	i = 0;
	if (find_stack_index(ctx->sa, nbr))
		i = stack_size(ctx->sa) - find_stack_index(ctx->sa, nbr);
	i = find_place_sb(ctx->sb, nbr) + i;
	return (i);
}

int	case_rarrb_ab(t_ctx *ctx, int nbr)
{
	int	i;

	i = 0;
	if (find_place_sb(ctx->sb, nbr))
		i = stack_size(ctx->sb) - find_place_sb(ctx->sb, nbr);
	i = find_stack_index(ctx->sa, nbr) + i;
	return (i);
}
