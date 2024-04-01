/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:53:04 by ixu               #+#    #+#             */
/*   Updated: 2023/12/23 22:27:42 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arr;
	int		status;

	a = NULL;
	b = NULL;
	arr = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2)
		arr = split_str(argv[1], ' ');
	if (arr != NULL)
		argv = arr;
	status = stack_init(argv, &a);
	if (status == 1)
	{
		free_input(arr);
		return (0);
	}
	if (!is_sorted(a))
		sort(&a, &b);
	free_stack(&a);
	free_input(arr);
	return (0);
}
