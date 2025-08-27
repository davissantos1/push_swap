#include "push_swap.c"

void    putstack_fd(void *head, int fd)
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
