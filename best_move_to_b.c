/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:19:02 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/18 20:19:14 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_node *head)
{
	int	a;
	int	i;
	int	j;

	j = 0;
	i = 0;
	a = head->data;
	while (head)
	{
		if (a < head->data)
		{
			a = head->data;
			j = i;
		}
		i++;
		head = head->next;
	}
	return (j);
}

int	ft_index(t_node *b, int data)
{
	int		i;
	int		j;
	t_node	*new;
	int		p;

	i = 0;
	new = b;
	j = -1;
	p = -2147483648;
	while (b)
	{
		if (b->data < data && b->data >= p)
		{
			p = b->data;
			j = i;
		}
		i++;
		b = b->next;
	}
	if (j == -1)
	{
		j = ft_max(new);
	}
	return (j);
}

int	maxnd(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	change_n(int *min_move, int mov, int *data, int stak_a)
{
	*min_move = mov;
	*data = stak_a;
}

int	best_move_to_b(t_node *stak_a, t_node *stak_b, int indx_b)
{
	int		data;
	int		i;
	int		mov;
	int		min_move;
	t_node	*new;

	min_move = 2147483647;
	i = -1;
	new = stak_a;
	while (stak_a && i++ >= -1)
	{
		indx_b = ft_index(stak_b, stak_a->data);
		if (i <= ft_lstsize(new) / 2 && indx_b <= ft_lstsize(stak_b) / 2)
			mov = maxnd(i, indx_b);
		else if (indx_b > ft_lstsize(stak_b) / 2 && i > ft_lstsize(new) / 2)
			mov = maxnd(ft_lstsize(new) - i, ft_lstsize(stak_b) - indx_b);
		else if (i > ft_lstsize(new) / 2 && indx_b <= ft_lstsize(stak_b) / 2)
			mov = (ft_lstsize(new) - i) + indx_b;
		else if (i <= ft_lstsize(new) / 2 && indx_b > ft_lstsize(stak_b) / 2)
			mov = (ft_lstsize(stak_b) - indx_b) + i;
		if (min_move > mov)
			change_n(&min_move, mov, &data, stak_a->data);
		stak_a = stak_a->next;
	}
	return (data);
}
