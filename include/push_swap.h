/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:02:35 by ixu               #+#    #+#             */
/*   Updated: 2023/12/23 23:00:35 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

/* cost: number of rotation (r, rr) operations 
needed to bring node to top of stack */

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				above_medium;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

// convert data to usable format
char	**split_str(char const *s, char c);
long	str_to_long(char *str, char **end_ptr);

// validate input
int		valid_input(char **argv);

// initialize stack 
int		stack_len(t_stack *a);
void	update_position(t_stack *stack);
int		stack_init(char **argv, t_stack **stack);

// free allocated memory, if necessary
void	free_input(char **arr_to_free);
void	free_stack(t_stack **stack);

// swap commands
void	sa(t_stack *a, int checker);
void	sb(t_stack *b, int checker);
void	ss(t_stack *a, t_stack *b, int checker);

// rotate commands
void	ra(t_stack **a, int checker);
void	rb(t_stack **b, int checker);
void	rr(t_stack **a, t_stack **b, int checker);

// reverse rotate commands
void	rra(t_stack **a, int checker);
void	rrb(t_stack **b, int checker);
void	rrr(t_stack **a, t_stack **b, int checker);

// push commands
void	pa(t_stack **b, t_stack **a, int checker);
void	pb(t_stack **a, t_stack **b, int checker);

// implement sorting algorithm
void	sort(t_stack **a, t_stack **b);

// helper funcs for sorting
int		is_sorted(t_stack *a);
void	rotate_a_b(t_stack **a, t_stack **b, t_stack *cheapest);
void	r_rotate_a_b(t_stack **a, t_stack **b, t_stack *cheapest);

// funcs for analyzing the costs
void	set_targets_for_a(t_stack *a, t_stack *b);
void	set_targets_for_b(t_stack *a, t_stack *b);
void	get_costs(t_stack *a, t_stack *b);
t_stack	*find_cheapest(t_stack *a);

// helper funcs for analyzing the costs
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
int		max(int a, int b);

#endif