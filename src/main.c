/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:15:00 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 14:06:58 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(int *arr, int *tmp, int *label)
{
	free(arr);
	free(tmp);
	free(label);
}

static void	ft_argv_to_ints(char **argv, int *arr, int *tmp, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		tmp[i] = arr[i];
		i++;
	}
}

static int	ft_malloc(int **arr, int **tmp, int **label, int num)
{
	*arr = malloc(sizeof(int) * num);
	if (!*arr)
	{
		ft_printf("Error\n");
		return (0);
	}
	*tmp = malloc(sizeof(int) * num);
	if (!*tmp)
	{
		ft_printf("Error\n");
		free(arr);
		return (0);
	}
	*label = malloc(sizeof(int) * num);
	if (!*label)
	{
		ft_printf("Error\n");
		free(arr);
		free(tmp);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		*tmp;
	int		*label;
	int		num;

	num = argc - 1;
	if (argc < 2 || !ft_valid_argv(argc, argv))
		return (0);
	arr = NULL;
	tmp = NULL;
	label = NULL;
	if (!ft_malloc(&arr, &tmp, &label, num))
		return (0);
	ft_argv_to_ints(argv, arr, tmp, num);
	if (ft_is_sorted(tmp, num))
	{
		ft_free(arr, tmp, label);
		return (0);
	}
	ft_normalize(arr, tmp, label, num);
	ft_stack(arr, tmp, label, num);
}
