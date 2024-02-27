/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:01:41 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/03 15:01:45 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **head, t_node **p)
{
	t_node	*a;

	if (*head == NULL)
		return ;
	a = *head;
	*head = a->next;
	a->next = NULL;
	ft_lstadd_front(p, a);
}

void	pb(t_node **head, t_node **p)
{
	push(head, p);
	write(1, "pb\n", 3);
}

void	pa(t_node **head, t_node **p)
{
	push(head, p);
	write(1, "pa\n", 3);
}
