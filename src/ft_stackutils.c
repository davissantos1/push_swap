#include "ft_push_swap.h"

t_stack	*ft_stack_createnode(int nbr, t_gc *gc, t_gc_tag tag)
{
	t_stack	*node;

	node = gc_malloc(sizeof(t_stack), gc, tag);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->last = NULL;
	node->num = nbr;
	return (node);
}

t_stack	*ft_stack_addtop(t_stack *head, t_stack *node)
{
	if (!head || !node)
		return (0);
	node->next = head;
	node->prev = NULL;
	node->last = head;
	if (head)
	{
		head->prev = node;
		head->last = head;
	}
	return (node);
}

t_stack	*ft_stack_init(t_ctx *ctx, t_gc *gc)
{
	t_stack	*node;
	int		i;

	i = ctx->size - 1;
	while (i >= 0)
	{
		node = ft_stack_createnode((ctx->arr)[i], gc, GC_TEMP);
		if (!node)
			return (gc_free_tag(gc, GC_TEMP));
		ctx->sa = ft_stack_addtop(ctx->sa, node);
		i--;
	}
	return (ctx->sa);
}
