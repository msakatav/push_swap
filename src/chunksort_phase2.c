/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort_phase2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:19:39 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 14:47:06 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *a, t_stack *b)
{
	if (a->elements >= 2 && a->content[0] > a->content[1])
	{
		if (b->elements >= 2 && b->content[0] < b->content[1])
			ft_ss(a, b);
		else
			ft_sa(a);
	}
}

static void	ft_rotate(t_stack *a, t_stack *b, int num_targets, int max)
{
	int	next;
	int	j;

	next = max - ft_check_num(b, max);
	if (next < 0)
		next = -1;
	j = 0;
	while (j <= num_targets - 2
		&& a->content[a->elements - 1] < a->capacity - 1)
	{
		if (should_use_rrb(b, next))
			ft_rrr(a, b);
		else
			ft_rra(a);
		j++;
	}
}

void	ft_chunksort_phase2(t_stack *a, t_stack *b)
{
	int	max;
	int	num_targets;

	max = a->capacity - 4;
	while (b->elements > 0)
	{
		num_targets = ft_check_num(b, max);
		ft_push_to_a(a, b, num_targets, max);
		ft_swap(a, b);
		max = max - (num_targets + 1);
		ft_rotate(a, b, num_targets, max);
	}
}
