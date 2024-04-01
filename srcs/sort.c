/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:03:22 by ixu               #+#    #+#             */
/*   Updated: 2023/12/23 23:03:44 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// if stack a has no more than three nbrs, sort the nbrs in ascending order

static void	sort_three(t_stack **a)
{
	t_stack	*second;
	t_stack	*last;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	if ((*a)->next->next == NULL)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(*a, 0);
		return ;
	}
	second = (*a)->next;
	last = second->next;
	if ((*a)->nbr > second->nbr && (*a)->nbr > last->nbr)
		ra(a, 0);
	else if (second->nbr > (*a)->nbr && second->nbr > last->nbr)
		rra(a, 0);
	second = (*a)->next;
	if ((*a)->nbr > second->nbr)
		sa(*a, 0);
}

/*
	rotating stacks depends on positions of cheapest and target
	1. cheapest, target above medium
	2. cheapest, target below medium
	3. cheapest above medium, target below medium
	4. cheapest below medium, target above medium
*/

static void	perform_rotation(t_stack **a, t_stack **b, t_stack *cheapest)
{
	t_stack	*target;
	int		a_len;
	int		b_len;

	a_len = stack_len(*a);
	b_len = stack_len(*b);
	target = cheapest->target;
	if (cheapest->above_medium && target->above_medium)
		rotate_a_b(a, b, cheapest);
	else if (!cheapest->above_medium && !target->above_medium)
		r_rotate_a_b(a, b, cheapest);
	else if (cheapest->above_medium && !target->above_medium)
	{
		while (cheapest->index-- > 0)
			ra(a, 0);
		while (target->index++ < b_len)
			rrb(b, 0);
	}
	else if (!cheapest->above_medium && target->above_medium)
	{
		while (cheapest->index++ < a_len)
			rra(a, 0);
		while (target->index-- > 0)
			rb(b, 0);
	}
}

static void	push_from_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;

	tmp_b = *b;
	update_position(*a);
	while (tmp_b != NULL)
	{
		set_targets_for_b(*a, *b);
		while (*a != tmp_b->target)
		{
			if (tmp_b->target->above_medium)
				ra(a, 0);
			else
				rra(a, 0);
		}
		tmp_b = tmp_b->next;
		pa(b, a, 0);
		update_position(*a);
	}
}

static void	min_to_top(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*min_node;

	tmp = *a;
	min_node = tmp;
	while (tmp != NULL)
	{
		if (min_node->nbr > tmp->nbr)
			min_node = tmp;
		tmp = tmp->next;
	}
	while (*a != min_node)
	{
		if (min_node->above_medium)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int		a_len;
	t_stack	*cheapest;

	a_len = stack_len(*a);
	if (a_len >= 4)
		pb(a, b, 0);
	if (a_len >= 5)
		pb(a, b, 0);
	update_position(*a);
	update_position(*b);
	while (stack_len(*a) > 3)
	{
		set_targets_for_a(*a, *b);
		get_costs(*a, *b);
		cheapest = find_cheapest(*a);
		perform_rotation(a, b, cheapest);
		pb(a, b, 0);
		update_position(*a);
		update_position(*b);
	}
	sort_three(a);
	push_from_b_to_a(a, b);
	min_to_top(a);
}
