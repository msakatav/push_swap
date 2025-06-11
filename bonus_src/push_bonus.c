/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:04:27 by msakata           #+#    #+#             */
/*   Updated: 2025/06/05 02:36:30 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->elements < 1)
		return ;
	i = a->elements;
	while (i > 0)
	{
		a->content[i] = a->content[i - 1];
		i--;
	}
	a->content[0] = b->content[0];
	i = 0;
	while (i < b->elements - 1)
	{
		b->content[i] = b->content[i + 1];
		i++;
	}
	a->elements++;
	b->elements--;
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->elements < 1)
		return ;
	i = b->elements;
	while (i > 0)
	{
		b->content[i] = b->content[i - 1];
		i--;
	}
	b->content[0] = a->content[0];
	i = 0;
	while (i < a->elements - 1)
	{
		a->content[i] = a->content[i + 1];
		i++;
	}
	b->elements++;
	a->elements--;
}
