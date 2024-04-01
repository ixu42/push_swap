/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:19:11 by ixu               #+#    #+#             */
/*   Updated: 2023/12/20 15:19:53 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_input(char **arr_to_free)
{
	int	i;

	i = 0;
	if (arr_to_free == NULL)
		return ;
	while (arr_to_free[i] != NULL)
	{
		free(arr_to_free[i]);
		i++;
	}
	free(arr_to_free);
}

void	free_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;

	current = *stack;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	prev = NULL;
	(*stack) = NULL;
}
