/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:32:43 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/18 20:32:49 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_indx_data(t_node *a, int data)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->data == data)
			return (i);
		i++;
		a = a->next;
	}
	return (0);
}

void	nt(int indxb, int indxa, t_node **stak_a, t_node **stak_b)
{
	while (indxb > 0 && indxa > 0)
	{
		rr(stak_a, stak_b);
		indxa--;
		indxb--;
	}
	while (indxb-- > 0)
		rb(stak_b);
	while (indxa-- > 0)
		ra(stak_a);
}

void	nt1(int indxb, int inda, t_node **stak_a, t_node **stak_b)
{
	while (indxb-- > 0)
		rb(stak_b);
	while (inda-- > 0)
		rra(stak_a);
}

void	nt2(int indb, int inda, t_node **stak_a, t_node **stak_b)
{
	while (indb > 0 && inda > 0)
	{
		rrr(stak_a, stak_b);
		inda--;
		indb--;
	}
	while (indb-- > 0)
		rrb(stak_b);
	while (inda-- > 0)
		rra(stak_a);
}

void	check_push(t_node **stac_a, t_node **stac_b, int data, int indxa)
{
	int	indxb;
	int	indb;
	int	inda;

	indxa = find_indx_data(*stac_a, data);
	indxb = 0;
	indxb = ft_index(*stac_b, data);
	indb = ft_lstsize(*stac_b) - indxb;
	inda = ft_lstsize(*stac_a) - (indxa);
	if (indxb <= ft_lstsize(*stac_b) / 2 && indxa <= ft_lstsize(*stac_a) / 2)
		nt(indxb, indxa, stac_a, stac_b);
	else if (indxb <= ft_lstsize(*stac_b) / 2 && indxa > ft_lstsize(*stac_a)
		/ 2)
		nt1(indxb, inda, stac_a, stac_b);
	else if (indxb > ft_lstsize(*stac_b) / 2 && indxa <= ft_lstsize(*stac_a)
		/ 2)
	{
		while (indb-- > 0)
			rrb(stac_b);
		while (indxa-- > 0)
			ra(stac_a);
	}
	else
		nt2(indb, inda, stac_a, stac_b);
	pb(stac_a, stac_b);
}
