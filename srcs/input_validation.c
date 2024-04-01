/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:22:10 by ixu               #+#    #+#             */
/*   Updated: 2023/12/20 16:10:05 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_zero(char *data)
{
	if (!ft_strlen(data))
		return (0);
	while (*data)
	{
		if (*data != '0')
			return (0);
		data++;
	}
	return (1);
}

static int	has_dup(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i + 1] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_input(char **argv)
{
	char	*end_ptr;
	long	num;
	int		i;

	if (argv[0] == NULL)
		return (0);
	i = 1;
	while (argv[i] != NULL)
	{
		num = str_to_long(argv[i], &end_ptr);
		if ((!num && !is_zero(argv[i])) || errno == ERANGE || *end_ptr != '\0')
			return (0);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	if (has_dup(argv))
		return (0);
	return (1);
}
