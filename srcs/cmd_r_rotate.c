/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:59:41 by ixu               #+#    #+#             */
/*   Updated: 2023/12/23 22:44:07 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	r_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	rra(t_stack **a, int checker)
{
	r_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int checker)
{
	r_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int checker)
{
	r_rotate(a);
	r_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
