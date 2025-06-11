/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 00:13:07 by msakata           #+#    #+#             */
/*   Updated: 2025/06/05 03:19:41 by msakata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	execute_command(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	ft_execute_command(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!execute_command(line, a, b))
		{
			ft_printf("Error\n");
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
	if (ft_is_sorted(a->content, a->elements) && b->elements == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
