/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:15:24 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/13 14:43:59 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes
# include "../libft/libft.h"
# include <unistd.h>

// Structs

// Stack structure
typedef struct		s_stack
{
	long			num;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Context structure
typedef struct		s_ctx
{
	struct s_stack	*sa;
	struct s_stack	*sb;
	int				*arr;
	int				*sorted;
	int				size;
}					t_ctx;

// Prototypes

// String utils
char	**parse_nbrs(int argc, char **argv);
int		parse_error(char **parsed);
int		is_valid_num(char *num);
int		*strings_to_ints(char **parsed, t_gc *gc);
int	find_index(int nbr, int *arr, int size);

// Stack utils
t_stack	*stack_createnode(int nbr, t_gc *gc, t_gc_tag tag);
t_stack	*stack_addtop(t_stack *head, t_stack *node);
t_stack	*stack_init(t_ctx *ctx, t_gc *gc);
long	stack_min(t_stack *stack);
long	stack_max(t_stack *stack);

// Context utils
t_ctx	*ctx_init(char **parsed, t_gc *gc);

// Main program and algorithm
int		push_swap(char **parsed, t_gc *gc);
void	push_swap_solver(t_ctx *ctx);
int		check_sa(t_stack *sa);
int		check_sb(t_stack *sb);

// Push swap operations
void	pa(t_stack **head_a, t_stack **head_b, int print);
void	pb(t_stack **head_a, t_stack **head_b, int print);
void	sa(t_stack **head_a, int print);
void	sb(t_stack **head_b, int print);
void	ss(t_stack **head_a, t_stack **head_b, int print);
void	ra(t_stack **head_a, int print);
void	rb(t_stack **head_b, int print);
void	rr(t_stack **head_a, t_stack **head_b, int print);
void	rra(t_stack **head_a, int print);
void	rrb(t_stack **head_b, int print);
void	rrr(t_stack **head_a, t_stack **head_b, int print);

#endif
