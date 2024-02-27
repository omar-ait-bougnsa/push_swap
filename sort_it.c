/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:02:50 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/03 15:02:57 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_node **stak_a, t_node **stak_b)
{
	int	data;
	int	j;
	int	indx;

	indx = 0;
	j = 0;
	data = 0;
	pb(stak_a, stak_b);
	if (ft_lstsize(*stak_a) > 3)
		pb(stak_a, stak_b);
	while (ft_lstsize(*stak_a) > 3)
	{
		data = best_move_to_b(*stak_a, *stak_b, j);
		check_push(stak_a, stak_b, data, indx);
	}
	sort_three(stak_a);
}

void	sort(t_node **stak_a)
{
	int	i;
	int	j;

	i = min(*stak_a);
	j = ft_lstsize(*stak_a) - i;
	if (i <= ft_lstsize(*stak_a) / 2)
	{
		while (i > 0)
		{
			ra(stak_a);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			rra(stak_a);
			j--;
		}
	}
}

void	sort_it(t_node **stak_a, t_node **stak_b)
{
	push_a_to_b(stak_a, stak_b);
	push_b_to_a(stak_b, stak_a);
	sort(stak_a);
}
