#include "ft_push_swap.h"

t_stack	*ft_stack_createnode(int nbr, t_gc *gc, t_gc_tag tag)
{
	t_stack	*node;

	node = gc_malloc(sizeof(t_stack), gc, tag);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->data = nbr;
	return (node);
}

void	ft_stack_addtop(t_stack **head, t_stack *node)
{
	if (node>next || node->prev)
		ft_stack_dettach(node);

	head->prev = node;
	node->next = head;
	node->prev = NULL;
}

t_stack	*ft_stack_init(t_stack *stack, int *arr, int size, t_gc *gc)
{
	t_stack	*node;
	int		count;

	count = 0;
	while (--size)
	{
		node = ft_stack_createnode(arr[size], gc, GC_TEMP);
		if (!node)
			return (gc_free_tag(gc, GC_TEMP));
		ft_stack_addtop(stack, node);
		count++;
	}
	return (node);
}
