/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:34:09 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 14:35:25 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_has_chunk_element(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i < a->elements)
	{
		if (a->content[i] >= min && a->content[i] <= max)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_is_top_in_chunk(t_stack *a, int min, int max)
{
	if (min == -1 || max == -1)
		return (0);
	if (a->elements == 0)
		return (0);
	if (a->content[0] >= min && a->content[0] <= max)
		return (1);
	return (0);
}

static void	ft_rotate_after_push(t_stack *a, t_stack *b, t_chunk_info *info,
								int chunk_element)
{
	if (chunk_element)
	{
		if (!ft_is_top_in_chunk(a, info->min_num, info->max_num))
			ft_rr(a, b);
		else
			ft_rb(b);
	}
	else if (info->chunk + 1 < info->chunk_count - 1)
	{
		if (!ft_is_top_in_chunk(a, info->next_min, info->next_max))
			ft_rr(a, b);
		else
			ft_rb(b);
	}
	else
		ft_rb(b);
}

void	ft_push_chunks_to_b(t_stack *a, t_stack *b, t_chunk_info *info)
{
	int	has_element;

	while (ft_has_chunk_element(a, info->min_num, info->max_num)
		&& a->elements > 3)
	{
		if (ft_is_top_in_chunk(a, info->min_num, info->max_num))
		{
			ft_pb(a, b);
			if (b->content[0] < (info->min_num + info->max_num) / 2)
			{
				has_element = ft_has_chunk_element(a,
						info->min_num, info->max_num);
				ft_rotate_after_push(a, b, info, has_element);
			}
		}
		else
			ft_ra(a);
	}
}
