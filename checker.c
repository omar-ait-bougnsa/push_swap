/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:40:53 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/20 20:40:56 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_node **a, t_node **b)
{
	swap(b);
	swap(a);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[i] != '\0' && ss2[i] != '\0' && ss1[i] == ss2[i])
	{
		i++;
	}
	return (ss1[i] - ss2[i]);
}

int	check_other(t_node **a, t_node **b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		reverse(a);
		reverse(b);
	}
	else
	{
		ft_free(a);
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

void	checker(t_node **a, t_node **b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		if (ft_strcmp(str, "pb\n") == 0)
			push(a, b);
		else if (ft_strcmp(str, "pa\n") == 0)
			push(b, a);
		else if (ft_strcmp(str, "sa\n") == 0)
			swap(a);
		else if (ft_strcmp(str, "sb\n") == 0)
			swap(b);
		else if (ft_strcmp(str, "ss\n") == 0)
			ss(a, b);
		else if (check_other(a, b, str) == 1)
		{
			free(str);
			return ;
		}
		free(str);
		str = get_next_line(0);
	}
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
		if (a != NULL)
			checker(&a, &b);
		if (a != NULL && b == NULL && check_sorted(a) == 0)
			write(1, "OK\n", 3);
		else if (a != NULL)
			write(1, "KO\n", 3);
		ft_free(&a);
		ft_free(&b);
	}
}
