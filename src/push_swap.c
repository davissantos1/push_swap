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

#include "push_swap.h"

t_ctx	*ctx_init(char **parsed, t_gc *gc)
{
	t_ctx	*ctx;

	ctx = gc_malloc(sizeof(t_ctx), gc, GC_DEFAULT);
	if (!ctx)
		return (0);
	ctx->size = ft_mtxlen(parsed);
	ctx->arr = strings_to_ints(parsed, gc);
	ctx->sorted = strings_to_ints(parsed, gc);
	if (!ctx->arr || !ctx->sorted)
		return (0);
	ctx->sorted = ft_bubble_sort_int(ctx->sorted, ctx->size);
	ctx->sa = NULL;
	ctx->sb = NULL;
	return (ctx);
}

int	push_swap(char **parsed, t_gc *gc)
{
	t_ctx	*ctx;

	ctx = ctx_init(parsed, gc);
	if (!ctx)
		return (0);
	ctx->sa = stack_init(ctx, gc);
	if (!ctx->sa)
		return (0);
	if (check_sa(ctx->sa))
		return (1);
	push_swap_solver(ctx);
	return (1);
}
