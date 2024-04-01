/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:37:28 by ixu               #+#    #+#             */
/*   Updated: 2023/12/28 13:37:28 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	handle_error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_cmd(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(a, b, 1);
	else if (!ft_strcmp(cmd, "pa\n"))
		pa(b, a, 1);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(a, b, 1);
	else if (!ft_strcmp(cmd, "sa\n"))
		sa(*a, 1);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(*b, 1);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(*a, *b, 1);
	else
		handle_error(a, b);
}

static void	check_sorting(t_stack **a, t_stack **b)
{
	int		a_len;
	char	*next_line;

	a_len = stack_len(*a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_cmd(a, b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(*a) && stack_len(*a) == a_len && stack_len(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
		return (1);
	}
	check_sorting(&a, &b);
	free_stack(&a);
	free_input(arr);
	return (0);
}
