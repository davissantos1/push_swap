#include "push_swap.h"

void	solve_three(t_stack **sa)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;

	first = *sa;
	second = first->next;
	third = second->next;
	if (!check_sa(*sa)) // first < second < third
		return ;	
	if (check_sb(*sa)) // first > second > third
	{
		rra(*sa, 1);
		sa(*sa, 1);
	}
	else if (first->num < second->num) // first < second > third 
	{
		sa(*sa, 1);
		ra(*sa, 1);
	}
	else  // first > second < third 
		ra(*sa, 1);
}	

void	push_swap_solver(t_ctx *ctx)
{
	int	i;

	if (ctx->size == 2)
		sa(&(ctx->sa), 1);
	else if (ctx->size == 3)
		solve_three(&(ctx->sa));
	else
	{
		
		i = find_index(stack_min(ctx->sa), ctx->arr, ctx->size);
		if (i < ctx-size - i)
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
