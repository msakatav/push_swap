/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:26:31 by msakata           #+#    #+#             */
/*   Updated: 2025/06/04 05:56:15 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	int	tmp;
	int	i;

	if (a->elements < 2)
		return ;
	tmp = a->content[a->elements - 1];
	i = a->elements - 1;
	while (i > 0)
	{
		a->content[i] = a->content[i - 1];
		i--;
	}
	a->content[0] = tmp;
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *b)
{
	int	tmp;
	int	i;

	if (b->elements < 2)
		return ;
	tmp = b->content[b->elements - 1];
	i = b->elements - 1;
	while (i > 0)
	{
		b->content[i] = b->content[i - 1];
		i--;
	}
	b->content[0] = tmp;
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack	*a, t_stack *b)
{
	int	tmp;
	int	i;

	if (a->elements < 2 || b->elements < 2)
		return ;
	tmp = a->content[a->elements - 1];
	i = a->elements - 1;
	while (i > 0)
	{
		a->content[i] = a->content[i - 1];
		i--;
	}
	a->content[0] = tmp;
	tmp = b->content[b->elements - 1];
	i = b->elements - 1;
	while (i > 0)
	{
		b->content[i] = b->content[i - 1];
		i--;
	}
	b->content[0] = tmp;
	ft_printf("rrr\n");
}
