/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:30:57 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/20 15:31:00 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **n)
{
	int	a;
	int	b;
	int	c;

	a = (*n)->data;
	b = (*n)->next->data;
	c = (*n)->next->next->data;
	if (a > b && a < c)
		sa(n);
	else if (a > b && b > c)
	{
		sa(n);
		rra(n);
	}
	else if (a > b && b < c)
		ra(n);
	else if (a < b && a > c)
		rra(n);
	else if (a < b && b > c)
	{
		sa(n);
		ra(n);
	}
}
