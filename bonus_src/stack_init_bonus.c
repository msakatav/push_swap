/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:51:51 by msakata           #+#    #+#             */
/*   Updated: 2025/06/05 03:17:13 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_free(int *arr)
{
	ft_printf("Error\n");
	free(arr);
}

static void	ft_free_stack(t_stack *a, t_stack *b)
{
	free(a->content);
	free(a);
	free(b->content);
	free(b);
}

static t_stack	*ft_init_stack_a(int *arr, int num)
{
	t_stack	*a;
	int		i;

	a = malloc(sizeof(t_stack));
	if (!a)
	{
		ft_free(arr);
		return (NULL);
	}
	a->content = malloc(sizeof(int) * num);
	if (!a->content)
	{
		free(a);
		ft_free(arr);
		return (NULL);
	}
	a->elements = num;
	a->capacity = num;
	i = 0;
	while (i < num)
	{
		a->content[i] = arr[i];
		i++;
	}
	return (a);
}

static t_stack	*ft_init_stack_b(int *arr, int num)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
	{
		ft_free(arr);
		return (NULL);
	}
	b->content = malloc(sizeof(int) * num);
	if (!b->content)
	{
		ft_free(arr);
		free(b);
		return (0);
	}
	b->elements = 0;
	b->capacity = num;
	return (b);
}

void	ft_stack_bonus(int *arr, int num)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_init_stack_a(arr, num);
	if (!a)
		return ;
	b = ft_init_stack_b(arr, num);
	if (!b)
	{
		free(a->content);
		free(a);
		return ;
	}
	free(arr);
	ft_execute_command(a, b);
	ft_free_stack(a, b);
}
