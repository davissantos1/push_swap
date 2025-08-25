#include "ft_push_swap.h"

void    ft_putstack_fd(void *head, int fd)
{
    t_stack	*stack;

    stack = (t_stack *)head;
    while (stack)
    {
		ft_putstr_fd("( ", fd);
		ft_putnbr_fd(stack->num, fd);
		ft_putstr_fd(" )", fd);
		if (stack->next)
			ft_putstr_fd("--", fd);
		stack = stack->next;
	}
}

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
	if (!node)
		return (head);
	if (!head)
	{
		node->next = NULL;
		node->prev = NULL;
		node->last = node;
		return (node);
	}
	node->next = head;
	node->prev = NULL;
	node->last = head->last;
	head->prev = node;
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
