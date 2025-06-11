/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:04:20 by msakata           #+#    #+#             */
/*   Updated: 2025/06/05 02:37:23 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->elements < 2)
		return ;
	tmp = a->content[0];
	i = 0;
	while (i < a->elements - 1)
	{
		a->content[i] = a->content[i + 1];
		i++;
	}
	a->content[a->elements - 1] = tmp;
}

void	rb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->elements < 2)
		return ;
	tmp = b->content[0];
	i = 0;
	while (i < b->elements - 1)
	{
		b->content[i] = b->content[i + 1];
		i++;
	}
	b->content[b->elements - 1] = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	int	tmp;
	int	i;

	if (a->elements < 2 || b->elements < 2)
		return ;
	tmp = a->content[0];
	i = 0;
	while (i < a->elements - 1)
	{
		a->content[i] = a->content[i + 1];
		i++;
	}
	a->content[a->elements - 1] = tmp;
	tmp = b->content[0];
	i = 0;
	while (i < b->elements - 1)
	{
		b->content[i] = b->content[i + 1];
		i++;
	}
	b->content[b->elements - 1] = tmp;
}
