#include "push_swap.h"

void	solve_three(t_ctx *ctx)
{
	t_stack *first;
	t_stack *second;

	first = ctx->sa;
	second = first->next;
	if (!check_sa(ctx->sa)) 	
		return ;	
	if (check_sb(ctx->sa))
	{
		rra(&ctx->sa, 1);
		sa(&ctx->sa, 1);
	}
	else if (first->num < second->num)
	{
		sa(&ctx->sa, 1);
		ra(&ctx->sa, 1);
	}
	else 
		ra(&ctx->sa, 1);
}	

void	solve_ab(t_ctx *ctx)
{
	t_stack *tmp;
	int	i;

	while (stack_size(ctx->sa) > 3)
	{
		tmp = ctx->sa;
		i = rotation_count_ab(ctx);
		while (i >= 0)
		{
			if (i == case_rr_ab(ctx, tmp->num))
				i = apply_rr(ctx, tmp->num, 0);
			else if (i == case_rrr_ab(ctx, tmp->num))
				i = apply_rrr(ctx, tmp->num, 0);
			else if (i == case_rrarb_ab(ctx, tmp->num))
				i = apply_rrarb(ctx, tmp->num, 0);
			else if (i == case_rarrb_ab(ctx, tmp->num))
				i = apply_rarrb(ctx, tmp->num, 0);
			else
				tmp = tmp->next;
		}
	}
}

void	solve_ba(t_ctx *ctx)
{
	t_stack *tmp;
	int	i;

	while (ctx->sb)
	{
		tmp = ctx->sb;
		i = rotation_count_ba(ctx);
		while (i >= 0)
		{
			if (i == case_rr_ba(ctx, tmp->num))
				i = apply_rr(ctx, tmp->num, 1);
			else if (i == case_rrr_ba(ctx, tmp->num))
				i = apply_rrr(ctx, tmp->num, 1);
			else if (i == case_rrarb_ba(ctx, tmp->num))
				i = apply_rrarb(ctx, tmp->num, 1);
			else if (i == case_rarrb_ba(ctx, tmp->num))
				i = apply_rarrb(ctx, tmp->num, 1);
			else
				tmp = tmp->next;
		}
	}
}

void	stack_solver(t_ctx *ctx)
{
	if (stack_size(ctx->sa) > 3)
		pb(&ctx->sa, &ctx->sb, 1);
	if (stack_size(ctx->sa) > 3)
		pb(&ctx->sa, &ctx->sb, 1);
	if (stack_size(ctx->sa) > 3 && !check_sa(ctx->sa))
		solve_ab(ctx);
	if (!check_sa(ctx->sa))
		solve_three(ctx);
	solve_ba(ctx);	
}

void	push_swap_solver(t_ctx *ctx)
{
	int	i;

	if (ctx->size == 2)
		sa(&(ctx->sa), 1);
	else if (ctx->size == 3)
		solve_three(ctx);
	else
	{
		stack_solver(ctx);
		i = find_index(stack_min(ctx->sa), ctx->arr, ctx->size);
		if (i < ctx->size - i)
		{
			while ((ctx->sa)->num != stack_min(ctx->sa))
				ra(&(ctx->sa), 1);
		}
		else
		{
			while ((ctx->sa)->num != stack_min(ctx->sa))
				rra(&(ctx->sa), 1);
		} 
	}
}
