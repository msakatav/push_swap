/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:04:17 by msakata           #+#    #+#             */
/*   Updated: 2025/06/02 10:28:52 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	int	tmp;

	if (a->elements < 2)
		return ;
	tmp = a->content[0];
	a->content[0] = a->content[1];
	a->content[1] = tmp;
	ft_printf("sa\n");
}

void	ft_sb(t_stack *b)
{
	int	tmp;

	if (b->elements < 2)
		return ;
	tmp = b->content[0];
	b->content[0] = b->content[1];
	b->content[1] = tmp;
	ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->elements < 2 || b->elements < 2)
		return ;
	tmp = a->content[0];
	a->content[0] = a->content[1];
	a->content[1] = tmp;
	tmp = b->content[0];
	b->content[0] = b->content[1];
	b->content[1] = tmp;
	ft_printf("ss\n");
}
