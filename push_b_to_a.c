/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:43:58 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/04 17:44:02 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	min(t_node *head)
{
	int	a;
	int	i;
	int	j;

	j = 0;
	i = 0;
	a = head->data;
	while (head)
	{
		if (a > head->data)
		{
			a = head->data;
			i = j;
		}
		j++;
		head = head->next;
	}
	return (i);
}

int	ft_index_a(t_node *b, int data)
{
	int		index;
	int		j;
	t_node	*new;
	long	p;

	j = -1;
	index = 0;
	new = b;
	p = 2147483648;
	while (b)
	{
		if (b->data > data && b->data < p)
		{
			p = b->data;
			j = index;
		}
		index++;
		b = b->next;
	}
	if (j == -1)
	{
		j = min(new);
	}
	return (j);
}

void	push_b_a(t_node **stac_b, t_node **stac_a)
{
	int	i;
	int	j;

	i = ft_index_a(*stac_a, (*stac_b)->data);
	j = ft_lstsize(*stac_a) - i;
	if (i <= (ft_lstsize(*stac_a) / 2))
	{
		while (i > 0)
		{
			ra(stac_a);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			rra(stac_a);
			j--;
		}
	}
	pa(stac_b, stac_a);
}

void	push_b_to_a(t_node **stak_b, t_node **stak_a)
{
	while (*stak_b)
	{
		push_b_a(stak_b, stak_a);
	}
}
