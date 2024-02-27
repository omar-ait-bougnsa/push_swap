/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:41:48 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/20 13:41:53 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **p)
{
	int	data1;

	if (ft_lstsize(*p) == 1)
		return ;
	data1 = (*p)->data;
	(*p)->data = (*p)->next->data;
	(*p)->next->data = data1;
}

void	sa(t_node **p)
{
	swap(p);
	write(1, "sa\n", 3);
}

void	sb(t_node **p)
{
	swap(p);
	write(1, "sb\n", 3);
}
