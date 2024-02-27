/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:20:02 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/18 20:20:06 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!lst && !new)
		return ;
	if (!lst)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = (*lst);
		*lst = new;
	}
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_node	*ft_lstnew(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_node *list)
{
	int	cont;

	cont = 0;
	while (list)
	{
		list = list->next;
		cont++;
	}
	return (cont);
}
