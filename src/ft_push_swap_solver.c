#include "ft_push_swap.h"

void	ft_push_swap_rops(t_stack *sa, t_stack *sb)
{
	if (sa && sa->last && (sa->num) > (sa->last)->num)
	{
		ft_push_swap_ra(&sa);
		ft_putstr_fd("ra\n", 1);
	}
	if (sa && sa->last && (sa->num) < (sa->last)->num)
	{
		ft_push_swap_rra(&sa);
		ft_putstr_fd("rra\n", 1);
	}
	if (sb && sb->last && (sb->num) > (sb->last)->num)
	{
		ft_push_swap_ra(&sb);
		ft_putstr_fd("rb\n", 1);
	}
	if (sb && sb->last && (sb->num) < (sb->last)->num)
	{
		ft_push_swap_rrb(&sb);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_push_swap_sops(t_stack *sa, t_stack *sb)
{
	if (sa && sa->next)
	{
		if (sa->num > (sa->next)->num) 
		{
			ft_push_swap_sa(&sa);
			ft_putstr_fd("sa\n", 1);
		}
	}
	if (sb && sb->next)
	{
		if (sb->num < (sb->next)->num) 
		{
			ft_push_swap_sb(&sb);
			ft_putstr_fd("sb\n", 1);
		}
	}
}

void	ft_push_swap_doubleops(t_stack *sa, t_stack *sb)
{
	if (sa && sa->next && sb && sb->next)
	{
		if ((sa->num > (sa->next)->num) && (sb->num < (sb->next)->num))
		{
			ft_push_swap_ss(&sa, &sb);
			ft_putstr_fd("ss\n", 1);
		}
		if ((sa->num > (sa->last)->num) && (sb->num < (sb->last)->num))
		{
			ft_push_swap_rr(&sa, &sb);
			ft_putstr_fd("rr\n", 1);
		}
		if ((sa->num < (sa->last)->num) && (sb->num > (sb->last)->num))
		{
			ft_push_swap_rrr(&sa, &sb);
			ft_putstr_fd("rrr\n", 1);
		}
	}
}
	
void	ft_push_swap_solver(t_ctx *ctx)
{
	while (ctx->control < (ctx->size) / 2)
	{
		ft_push_swap_doubleops(ctx->sa, ctx->sb);
		ft_push_swap_pb(&(ctx->sa), &(ctx->sb));
		ft_putstr_fd("pb\n", 1);
		ctx->control++;
	}
	while (ft_push_swap_check_sa(ctx->sa) || ft_push_swap_check_sb(ctx->sb))
	{
		ft_push_swap_doubleops(ctx->sa, ctx->sb);
		ft_push_swap_rops(ctx->sa, ctx->sb);
		ft_push_swap_doubleops(ctx->sa, ctx->sb);
		ft_push_swap_sops(ctx->sa, ctx->sb);
	}
	while (ctx->control)
	{
		ft_push_swap_pa(&(ctx->sa), &(ctx->sb));
		ft_putstr_fd("pa\n", 1);
		ctx->control--;
	}
}
