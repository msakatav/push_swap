/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 23:48:03 by msakata           #+#    #+#             */
/*   Updated: 2025/06/05 01:49:06 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_argv_to_ints(char **argv, int *arr, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

static int	ft_malloc(int **arr, int num)
{
	*arr = malloc(sizeof(int) * num);
	if (!*arr)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		num;

	num = argc - 1;
	if (argc < 2 || !ft_valid_argv(argc, argv))
		return (0);
	arr = NULL;
	if (!ft_malloc(&arr, num))
		return (0);
	ft_argv_to_ints(argv, arr, num);
	if (ft_is_sorted(arr, num))
	{
		free(arr);
		return (0);
	}
	ft_stack_bonus(arr, num);
}
