/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:45:33 by ixu               #+#    #+#             */
/*   Updated: 2023/12/20 15:59:25 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	convert(int is_neg, long *result, char *str)
{
	if (is_neg == 0)
	{
		if (*result > LONG_MAX / 10)
			return (-1);
		*result = *result * 10;
		if (*result > LONG_MAX - (*str - '0'))
			return (-1);
		*result = *result + (*str - '0');
	}
	else
	{
		if (*result < LONG_MIN / 10)
			return (0);
		*result = *result * 10;
		if (*result < LONG_MIN + (*str - '0'))
			return (0);
		*result = *result - (*str - '0');
	}
	return (1);
}

static int	skip_spaces(int *is_neg, char **str)
{
	int	status;

	status = 1;
	while (*(*str) == ' '
		|| (*(*str) >= 9 && *(*str) <= 13))
		(*str)++;
	if (ft_isdigit((*str)[0]) == 0 && ft_isdigit((*str)[1]) == 0)
		status = 0;
	if ((*str)[0] == '-' && ft_isdigit((*str)[1]) == 1)
		*is_neg = 1;
	if ((*str)[0] == '-' || (*str)[0] == '+')
		(*str)++;
	return (status);
}

long	str_to_long(char *str, char **end_ptr)
{
	long	result;
	int		is_neg;
	int		status;

	is_neg = 0;
	if (ft_strlen(str) == 0)
		return (0);
	status = skip_spaces(&is_neg, &str);
	if (status == 0)
		return (0);
	result = 0;
	while (ft_isdigit(*str))
	{
		status = convert(is_neg, &result, str);
		if (status == -1 || status == 0)
			errno = ERANGE;
		if (status == -1)
			return (LONG_MAX);
		if (status == 0)
			return (LONG_MIN);
		str++;
	}
	*end_ptr = str;
	return (result);
}
