#include "push_swap.h"

t_stack *stack_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*stack_createnode(int nbr, t_gc *gc, t_gc_tag tag)
{
	t_stack	*node;

	node = gc_malloc(sizeof(t_stack), gc, tag);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->num = nbr;
	return (node);
}

t_stack	*stack_addtop(t_stack *head, t_stack *node)
{
	if (!node)
		return (head);
	if (!head)
	{
		node->next = NULL;
		node->prev = NULL;
		return (node);
	}
	node->next = head;
	node->prev = NULL;
	head->prev = node;
	return (node);
}

t_stack	*stack_init(t_ctx *ctx, t_gc *gc)
{
	t_stack	*node;
	int		i;

	node = NULL;
	i = ctx->size - 1;
	while (i >= 0)
	{
		node = stack_createnode((ctx->arr)[i], gc, GC_TEMP);
		if (!node)
			return (gc_free_tag(gc, GC_TEMP));
		ctx->sa = stack_addtop(ctx->sa, node);
		i--;
	}
	return (ctx->sa);
}
