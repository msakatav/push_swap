/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmun_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:25:09 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 14:05:18 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_stack *a)
{
	if (a->content[0] > a->content[1])
		ft_sa(a);
}

void	ft_sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->content[0];
	y = a->content[1];
	z = a->content[2];
	if (x < y && y < z)
		return ;
	else if (x > y && y < z && x < z)
		ft_sa(a);
	else if (x > y && y > z)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (x > y && y < z && x > z)
		ft_ra(a);
	else if (x < y && y > z && x < z)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (x < y && y > z && x > z)
		ft_rra(a);
}

static int	ft_find_min_index(t_stack *a)
{
	int	i;
	int	min;
	int	min_index;

	i = 1;
	min = a->content[0];
	min_index = 0;
	while (i < a->elements)
	{
		if (a->content[i] < min)
		{
			min = a->content[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	ft_sort_5(t_stack *a, t_stack *b)
{
	int	min_index;

	while (a->elements > 3)
	{
		min_index = ft_find_min_index(a);
		if (min_index <= a->elements / 2)
			while (min_index-- > 0)
				ft_ra(a);
		else
			while (min_index++ < a->elements)
				ft_rra(a);
		ft_pb(a, b);
	}
	ft_sort_3(a);
	while (b->elements > 0)
		ft_pa(a, b);
}
