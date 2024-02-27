/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:33:23 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/18 20:33:28 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **head)
{
	t_node	*n;

	if (*head == NULL)
		return ;
	n = *head;
	while (n->next != NULL)
	{
		n = n->next;
	}
	n->next = *head;
	*head = (*head)->next;
	n->next->next = NULL;
}

void	ra(t_node **head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	rb(t_node **head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	rr(t_node **head, t_node **head1)
{
	rotate(head);
	rotate(head1);
	write(1, "rr\n", 3);
}
