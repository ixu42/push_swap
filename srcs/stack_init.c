/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:02:00 by ixu               #+#    #+#             */
/*   Updated: 2023/12/23 22:56:32 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*get_node(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = data;
	new_node->index = 0;
	new_node->above_medium = 0;
	new_node->cost = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	return (new_node);
}

static void	add_stack(t_stack **stack, t_stack **prev, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else if (*prev != NULL)
		(*prev)->next = new;
}

int	stack_len(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	update_position(t_stack *stack)
{
	t_stack	*tmp;
	int		len;
	int		i;

	tmp = stack;
	len = stack_len(stack);
	i = 0;
	while (tmp != NULL)
	{
		tmp->index = i;
		if (i <= len / 2)
			tmp->above_medium = 1;
		else
			tmp->above_medium = 0;
		tmp = tmp->next;
		i++;
	}
}

int	stack_init(char **argv, t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;
	int		i;

	if (!valid_input(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	current = NULL;
	i = 1;
	while (argv[i] != NULL)
	{
		prev = current;
		current = get_node(ft_atoi(argv[i]));
		add_stack(stack, &prev, current);
		i++;
	}
	update_position(*stack);
	return (0);
}
