/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort_phase1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:22:16 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 14:29:10 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chunk_size_init(t_stack *a, int chunk_count)
{
	int	chunk_size;

	chunk_size = a->capacity / chunk_count;
	if (chunk_size == 0)
		chunk_size = 1;
	return (chunk_size);
}

static void	ft_get_chunk_range(t_stack *a, t_chunk_info *info, int chunk_count)
{
	info->min_num = info->chunk * info->chunk_size;
	if (info->chunk == chunk_count - 1)
		info->max_num = a->capacity - 4;
	else
		info->max_num = (info->chunk + 1) * info->chunk_size - 1;
	if (info->chunk + 1 < chunk_count - 1)
	{
		info->next_min = (info->chunk + 1) * info->chunk_size;
		if (info->chunk + 2 == chunk_count)
			info->next_max = a->capacity - 4;
		else
			info->next_max = (info->chunk + 2) * info->chunk_size - 1;
	}
	else
	{
		info->next_min = -1;
		info->next_max = -1;
	}
}

void	ft_chunksort_phase1(t_stack *a, t_stack *b, int chunk_count)
{
	t_chunk_info	*info;

	info = malloc(sizeof(t_chunk_info));
	if (!info)
	{
		ft_printf("Error\n");
		free(a);
		free(b);
		return ;
	}
	info->chunk_size = ft_chunk_size_init(a, chunk_count);
	info->chunk = 0;
	info->chunk_count = chunk_count;
	while (info->chunk < chunk_count)
	{
		ft_get_chunk_range(a, info, chunk_count);
		ft_push_chunks_to_b(a, b, info);
		info->chunk++;
	}
	free(info);
	ft_sort_3(a);
	ft_chunksort_phase2(a, b);
}
