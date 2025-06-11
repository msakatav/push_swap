/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:01:14 by msakata           #+#    #+#             */
/*   Updated: 2025/06/01 22:02:34 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_selection_sort(int *tmp, int size)
{
	int	i;
	int	j;
	int	min_idx;
	int	t;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (tmp[j] < tmp[min_idx])
				min_idx = j;
			j++;
		}
		if (min_idx != i)
		{
			t = tmp[i];
			tmp[i] = tmp[min_idx];
			tmp[min_idx] = t;
		}
		i++;
	}
}
