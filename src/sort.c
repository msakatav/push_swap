/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:43:44 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 12:39:06 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	int	chunk_count;

	if (a->elements == 2)
		ft_sort_2(a);
	else if (a->elements == 3)
		ft_sort_3(a);
	else if (a->elements <= 5)
		ft_sort_5(a, b);
	else
	{
		if (a->capacity <= 15)
			chunk_count = 1;
		else if (a->capacity <= 100)
			chunk_count = 5;
		else if (a->capacity <= 500)
			chunk_count = 10;
		else
			chunk_count = 15;
		ft_chunksort_phase1(a, b, chunk_count);
	}
}
