/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:01:33 by ixu               #+#    #+#             */
/*   Updated: 2023/12/23 23:01:41 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// before sorting, check if the stack is already sorted

int	is_sorted(t_stack *a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (a == NULL || a->next == NULL)
		return (1);
	tmp1 = a;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp1->nbr > tmp2->nbr)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

void	rotate_a_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	t_stack	*target;

	target = cheapest->target;
	if (cheapest->index <= target->index)
	{
		target->index = target->index - cheapest->index;
		while (cheapest->index-- > 0)
			rr(a, b, 0);
		while (target->index-- > 0)
			rb(b, 0);
	}
	else
	{
		cheapest->index = cheapest->index - target->index;
		while (target->index-- > 0)
			rr(a, b, 0);
		while (cheapest->index-- > 0)
			ra(a, 0);
	}
}

void	r_rotate_a_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int		a_len;
	int		b_len;
	t_stack	*target;

	a_len = stack_len(*a);
	b_len = stack_len(*b);
	target = cheapest->target;
	if (a_len - cheapest->index <= b_len - target->index)
	{
		target->index = b_len - target->index - (a_len - cheapest->index);
		while (cheapest->index++ < a_len)
			rrr(a, b, 0);
		while (target->index-- > 0)
			rrb(b, 0);
	}
	else
	{
		cheapest->index = a_len - cheapest->index - (b_len - target->index);
		while (target->index++ < b_len)
			rrr(a, b, 0);
		while (cheapest->index-- > 0)
			rra(a, 0);
	}
}
