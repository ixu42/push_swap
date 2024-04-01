/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:53:31 by ixu               #+#    #+#             */
/*   Updated: 2023/12/18 15:47:51 by ixu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	**split_empty_str(void)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 1);
	if (arr != NULL)
		arr[0] = NULL;
	return (arr);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			count++;
			s++;
			while (*s == c)
				s++;
		}
		else
			s++;
	}
	s--;
	if (*s == c)
		return (count);
	else
		return (count + 1);
}

static void	free_arr(char **arr, int k)
{
	int	i;

	i = 0;
	while (i <= k)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**fill_arr(char const **ptr_to_s, char c, char **arr, int *ptr_to_k)
{
	int	len;
	int	i;

	len = 0;
	while ((*ptr_to_s)[len] != c && (*ptr_to_s)[len])
		len++;
	arr[*ptr_to_k] = (char *)malloc(sizeof(char) * (len + 1));
	if (arr[*ptr_to_k] == NULL)
	{
		free_arr(arr, *ptr_to_k);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		arr[*ptr_to_k][i] = (*ptr_to_s)[i];
		i++;
	}
	arr[*ptr_to_k][i] = '\0';
	while (*(*ptr_to_s) != c && *(*ptr_to_s))
		(*ptr_to_s)++;
	while (*(*ptr_to_s) == c && *(*ptr_to_s))
		(*ptr_to_s)++;
	(*ptr_to_k)++;
	return (arr);
}

/*
	split string s to an array of strings
	'\0' for arr[0] to mimic argv
*/

char	**split_str(char const *s, char c)
{
	char	**arr;
	int		k;

	if (ft_strlen(s) == 0)
		return (split_empty_str());
	arr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 2));
	if (arr == NULL)
		return (NULL);
	arr[0] = malloc(sizeof(char));
	*(arr[0]) = '\0';
	k = 1;
	while (*s == c)
		s++;
	while (*s != '\0')
	{
		arr = fill_arr(&s, c, arr, &k);
		if (arr == NULL)
			return (NULL);
	}
	arr[k] = NULL;
	return (arr);
}
