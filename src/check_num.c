/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:52:55 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 11:53:37 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_steps_to_top(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->elements)
	{
		if (stack->content[i] == value)
			break ;
		i++;
	}
	if (i == stack->elements)
		return (-1);
	if (i <= stack->elements / 2)
		return (i);
	else
		return (stack->elements - i);
}

int	ft_check_num(t_stack *b, int max)
{
	int	i;
	int	steps_current;
	int	steps_next;

	i = 0;
	if (b->elements == 1)
		return (i);
	while (max - i >= 0)
	{
		steps_current = count_steps_to_top(b, max - i);
		steps_next = count_steps_to_top(b, max - i - 1);
		if (steps_current > steps_next)
			i++;
		else
			break ;
	}
	return (i);
}
