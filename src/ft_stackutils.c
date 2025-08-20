#include "ft_push_swap.h"

t_stack	*ft_stack_createnode(int nbr, t_gc *gc, t_gc_tag tag)
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

void	ft_stack_addtop(t_stack **head, t_stack *node)
{
	if (!head || !node)
		return ;
	node->next = *head;
	node->prev = NULL;
	if (*head)
		(*head)->prev = node;
	*head = node;
}

t_stack	*ft_stack_init(t_stack *stack, int *arr, int size, t_gc *gc)
{
	t_stack	*node;
	int		count;
	int		i;

	i = size - 1;
	count = 0;
	while (i >= 0)
	{
		node = ft_stack_createnode(arr[i], gc, GC_TEMP);
		if (!node)
			return (gc_free_tag(gc, GC_TEMP));
		ft_stack_addtop(&stack, node);
		count++;
		i--;
	}
	return (stack);
}
