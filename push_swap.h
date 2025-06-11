/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:03:59 by msakata           #+#    #+#             */
/*   Updated: 2025/06/05 00:14:30 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int	*content;
	int	elements;
	int	capacity;
}	t_stack;

typedef struct s_chunk_info
{
	int	chunk_index;
	int	chunk_size;
	int	chunk;
	int	chunk_count;
	int	min_num;
	int	max_num;
	int	next_min;
	int	next_max;
}	t_chunk_info;

void	ft_ss(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rrr(t_stack	*a, t_stack *b);
void	ft_chunksort_phase1(t_stack *a, t_stack *b, int chunk_count);
void	ft_chunksort_phase2(t_stack *a, t_stack *b);
int		ft_check_num(t_stack *b, int max);
int		ft_valid_argv(int argc, char **argv);
void	ft_sort_2(t_stack *a);
void	ft_sort_3(t_stack *a);
void	ft_sort_5(t_stack *a, t_stack *b);
void	ft_normalize(int *arr, int *tmp, int *label, int num);
void	ft_push_chunks_to_b(t_stack *a, t_stack *b, t_chunk_info *info);
void	ft_selection_sort(int *tmp, int size);
void	ft_sort(t_stack *a, t_stack *b);
int		ft_is_sorted(int *arr, int size);
void	ft_stack(int *arr, int *tmp, int *label, int num);
int		ft_atol(const char *nptr);
void	ft_push_to_a(t_stack *a, t_stack *b, int num_targets, int max);
int		should_use_rrb(t_stack *stack, int value);
void	ft_rotate_stack_to_top(t_stack *stack, int value);

#endif