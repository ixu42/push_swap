/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_cost_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:17:43 by ixu               #+#    #+#             */
/*   Updated: 2023/12/28 00:17:43 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_targets_for_a(t_stack *a, t_stack *b)
{
	t_stack	*closest_smaller_in_b;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a;
	while (tmp_a != NULL)
	{
		tmp_b = b;
		closest_smaller_in_b = NULL;
		while (tmp_b != NULL)
		{
			if (tmp_b->nbr < tmp_a->nbr && closest_smaller_in_b == NULL)
				closest_smaller_in_b = tmp_b;
			else if (closest_smaller_in_b != NULL && tmp_b->nbr < tmp_a->nbr
				&& tmp_b->nbr > closest_smaller_in_b->nbr)
				closest_smaller_in_b = tmp_b;
			tmp_b = tmp_b->next;
		}
		if (closest_smaller_in_b != NULL)
			tmp_a->target = closest_smaller_in_b;
		else
			tmp_a->target = find_max(b);
		tmp_a = tmp_a->next;
	}
}

void	set_targets_for_b(t_stack *a, t_stack *b)
{
	t_stack	*closest_bigger_in_a;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_b = b;
	while (tmp_b != NULL)
	{
		tmp_a = a;
		closest_bigger_in_a = NULL;
		while (tmp_a != NULL)
		{
			if (tmp_a->nbr > tmp_b->nbr && closest_bigger_in_a == NULL)
				closest_bigger_in_a = tmp_a;
			else if (closest_bigger_in_a != NULL && tmp_a->nbr > tmp_b->nbr
				&& tmp_a->nbr < closest_bigger_in_a->nbr)
				closest_bigger_in_a = tmp_a;
			tmp_a = tmp_a->next;
		}
		if (closest_bigger_in_a != NULL)
			tmp_b->target = closest_bigger_in_a;
		else
			tmp_b->target = find_min(a);
		tmp_b = tmp_b->next;
	}
}

void	get_costs(t_stack *a, t_stack *b)
{
	t_stack	*dest;
	int		a_len;
	int		b_len;

	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a != NULL)
	{
		dest = a->target;
		if (a->above_medium && dest->above_medium)
			a->cost = max(a->index, dest->index);
		else if (!a->above_medium && !dest->above_medium)
			a->cost = max(a_len - a->index, b_len - dest->index);
		else if (a_len % 2 == 0 && a->index == a_len / 2 && !dest->above_medium)
			a->cost = max(a_len - a->index, b_len - dest->index);
		else if (b_len % 2 == 0 && dest->index == b_len / 2 && !a->above_medium)
			a->cost = max(a_len - a->index, b_len - dest->index);
		else if (a->above_medium && !dest->above_medium)
			a->cost = a->index + b_len - dest->index;
		else
			a->cost = a_len - a->index + dest->index;
		a = a->next;
	}
}

t_stack	*find_cheapest(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	cheapest = a;
	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->cost < cheapest->cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}
