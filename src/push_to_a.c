/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:20:17 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 12:59:12 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	should_use_rrb(t_stack *stack, int value)
{
	int	i;

	if (value < 0)
		return (0);
	i = 0;
	while (i < stack->elements)
	{
		if (stack->content[i] == value)
			break ;
		i++;
	}
	if (i == stack->elements)
		return (-1);
	return (i > (stack->elements / 2));
}

void	ft_rotate_stack_to_top(t_stack *stack, int value)
{
	if (stack->content[0] == value)
		return ;
	else if (should_use_rrb(stack, value))
	{
		while (stack->content[0] != value)
			ft_rrb(stack);
	}
	else
	{
		while (stack->content[0] != value)
			ft_rb(stack);
	}
}

void	ft_push_to_a(t_stack *a, t_stack *b, int num_targets, int max)
{
	int	i;
	int	current;

	while (b->elements <= 2 && b->elements > 0)
		ft_pa(a, b);
	i = 0;
	while (i <= num_targets && b->elements > 0)
	{
		current = max - num_targets + i;
		ft_rotate_stack_to_top(b, current);
		if (i == num_targets || i == num_targets - 1)
			ft_pa(a, b);
		else
		{
			ft_pa(a, b);
			if (!should_use_rrb(b, current))
				ft_rr(a, b);
			else
				ft_ra(a);
		}
		i++;
	}
}
