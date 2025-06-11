/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:35:27 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 12:32:46 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_rank(int *tmp, int size, int key)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = size - 1;
	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (tmp[mid] == key)
			return (mid);
		else if (tmp[mid] < key)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return (-1);
}

void	ft_normalize(int *arr, int *tmp, int *label, int num)
{
	int	i;
	int	rank;

	ft_selection_sort(tmp, num);
	i = 0;
	while (i < num)
	{
		rank = ft_find_rank(tmp, num, arr[i]);
		label[i] = rank;
		i++;
	}
}
