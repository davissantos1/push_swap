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
typedef struct		s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*last;
	int				num;
}					t_stack;

typedef struct		s_ctx
{
	struct s_stack	*sa;
	struct s_stack	*sb;
	int				*arr;
	int				size;
	int				control;
}					t_ctx;

// Prototypes
char	**ft_parse_nbrs(int argc, char **argv);
int		ft_parse_error(char **parsed);
int		ft_is_valid_num(char *num);
int		*ft_strings_to_ints(char **parsed, t_gc *gc);
int		ft_push_swap(char **parsed, t_gc *gc);
int		ft_push_swap_check_sa(t_stack *sa);
int		ft_push_swap_check_sb(t_stack *sb);
void	ft_push_swap_pa(t_stack **head_a, t_stack **head_b);
void	ft_push_swap_pb(t_stack **head_a, t_stack **head_b);
void	ft_push_swap_sa(t_stack **head_a);
void	ft_push_swap_sb(t_stack **head_b);
void	ft_push_swap_ss(t_stack **head_a, t_stack **head_b);
void	ft_push_swap_ra(t_stack **head_a);
void	ft_push_swap_rb(t_stack **head_b);
void	ft_push_swap_rr(t_stack **head_a, t_stack **head_b);
void	ft_push_swap_rra(t_stack **head_a);
void	ft_push_swap_rrb(t_stack **head_b);
void	ft_push_swap_rrr(t_stack **head_a, t_stack **head_b);
void	ft_push_swap_rops(t_stack *sa, t_stack *sb);
void	ft_push_swap_sops(t_stack *sa, t_stack *sb);
void	ft_push_swap_doubleops(t_stack *sa, t_stack *sb);
void	ft_push_swap_solver(t_ctx *ctx);
t_ctx	*ft_ctx_init(char **parsed, t_gc *gc);
t_stack	*ft_stack_createnode(int nbr, t_gc *gc, t_gc_tag tag);
t_stack	*ft_stack_addtop(t_stack *head, t_stack *node);
t_stack	*ft_stack_init(t_ctx *ctx, t_gc *gc);

#endif
