/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:02:19 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/03 15:02:27 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_node **head)
{
	t_node	*p;

	if (*head == NULL)
		return ;
	while ((*head)->next != NULL)
	{
		p = (*head)->next;
		free(*head);
		*head = p;
	}
	free(*head);
	*head = NULL;
}

void	ft_free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

t_node	*apend_t_node(char **av)
{
	int		i;
	long	data;
	t_node	*head;
	t_node	*new;

	data = 0;
	i = 0;
	head = NULL;
	while (av && av[i])
	{
		data = ft_atoi(av[i]);
		if (data > 2147483647 || data < -2147483648)
		{
			ft_free_av(av);
			ft_free(&head);
			write(2, "Error\n", 6);
			return (NULL);
		}
		new = ft_lstnew(data);
		ft_lstadd_back(&head, new);
		i++;
	}
	ft_free_av(av);
	return (head);
}

void	check_dabel(t_node **haed)
{
	t_node	*b;
	t_node	*a;

	a = *haed;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->data == b->data)
			{
				write(2, "Error\n", 6);
				ft_free(haed);
				return ;
			}
			b = b->next;
		}
		a = a->next;
	}
}

int	cheack_vid_av(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] != ' ' && av[i][j] != '\t')
				break ;
			j++;
		}
		if (av[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
