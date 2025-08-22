/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 23:22:19 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/21 18:53:17 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_ctx	*ft_ctx_init(char **parsed, t_gc *gc)
{
	t_ctx	*ctx;

	ctx = gc_malloc(sizeof(t_ctx), gc, GC_DEFAULT);
	if (!ctx)
		return (0);
	ctx->control = 0;
	ctx->size = ft_mtxlen(parsed);
	ctx->arr = ft_strings_to_ints(parsed, gc);
	if (!ctx->arr)
		return (0);
	ctx->arr = ft_bubble_sort_int(ctx->arr, ctx->size);
	ctx->sa = gc_malloc(sizeof(t_stack), gc, GC_DEFAULT);
	if (!ctx->sa)
		return (0);
	ctx->sb = gc_malloc(sizeof(t_stack), gc, GC_DEFAULT);
	if (!ctx->sb)
		return (0);
	return (ctx);
}

int	ft_push_swap(char **parsed, t_gc *gc)
{
	t_ctx	*ctx;

	ctx = ft_ctx_init(parsed, gc);
	if (!ctx)
		return (0);
	ctx->sa = ft_stack_init(ctx, gc);
	if (!ctx->sa)
		return (0);
	ft_push_swap_solver(ctx);
	return (1);
}
