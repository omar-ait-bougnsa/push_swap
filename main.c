/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:51:22 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/23 14:51:25 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_node *a)
{
	int	i;

	i = 0;
	while (a->next != NULL)
	{
		i = a->next->data;
		if (i < a->data)
			return (1);
		a = a->next;
	}
	ft_free(&a);
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;
	char	*str;

	b = NULL;
	i = 1;
	if (ac > 1 && cheack_vid_av(av) == 1)
	{
		while (av[i])
			str = ft_strjoin(str, av[i++]);
		av = ft_split(str, ' ');
		a = apend_t_node(av);
		check_dabel(&a);
		if (a == NULL || check_sorted(a) == 0)
			return (0);
		if (ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_three(&a);
		else
			sort_it(&a, &b);
		ft_free(&a);
	}
}
