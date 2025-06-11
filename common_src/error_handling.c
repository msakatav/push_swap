/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 03:29:06 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 12:00:15 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_int_range(char *str)
{
	long	num;

	num = atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	ft_has_duplicates(int *arr, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_free(int *tmp)
{
	ft_printf("Error\n");
	free(tmp);
}

int	ft_valid_argv(int argc, char **argv)
{
	int		i;
	int		*tmp;

	tmp = malloc(sizeof(int) * (argc -1));
	if (!tmp)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!ft_is_valid_number(argv[i]) || !ft_is_int_range(argv[i]))
		{
			ft_free(tmp);
			return (0);
		}
		tmp[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (ft_has_duplicates(tmp, argc - 1))
	{
		ft_free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
