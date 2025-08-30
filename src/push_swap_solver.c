/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 22:40:21 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/29 22:51:46 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 9 8 10 (sa) OK
// 10 9 8 (sa, rra) 
// 8 10 9 (sa, ra) OK
// 9 10 8 (rra)
// 10 8 9 (ra) OK
// 8 9 10 (OK)
void	solve_three(t_ctx *ctx)
{
	int	small;

	if (check_sa(ctx->sa))
		return ;
	small = stack_min(ctx->sa);
	if (ctx->sa->num == small)
	{
		sa(&ctx->sa, 1);
		ra(&ctx->sa, 1);
	}
	else if (ctx->sa->next->num == small)
	{
		if (ctx->sa->num > ctx->sa->next->next->num)
			ra(&ctx->sa, 1);
		else
			sa(&ctx->sa, 1);
	}
	else
	{
		if (ctx->sa->num > ctx->sa->next->num)
			sa(&ctx->sa, 1);
		rra(&ctx->sa, 1);
	}
}

void	solve_ab(t_ctx *ctx)
{
	t_stack	*tmp;
	int		i;

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
	t_stack	*tmp;
	int		i;

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
