/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:26:37 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/04 11:26:44 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_node **head)
{
	t_node	*n;
	t_node	*p;

	if (*head == NULL || ft_lstsize(*head) == 1)
		return ;
	n = *head;
	while (n->next != NULL)
	{
		p = n;
		n = n->next;
	}
	n->next = *head;
	*head = n;
	p->next = NULL;
}

void	rra(t_node **head)
{
	reverse(head);
	write(1, "rra\n", 4);
}

void	rrb(t_node **head)
{
	reverse(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **head, t_node **head1)
{
	reverse(head);
	reverse(head1);
	write(1, "rrr\n", 4);
}
