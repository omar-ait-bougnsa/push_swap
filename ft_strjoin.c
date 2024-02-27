/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:33:54 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/18 20:34:01 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	i = 0;
	if (s1 == NULL)
	{
		p = malloc(ft_strlen(s2) + 1);
		ft_strcpy(p, s2);
		return (p);
	}
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (p == NULL)
		return (0);
	while (s1[j])
		p[i++] = s1[j++];
	j = 0;
	p[i] = ' ';
	i++;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}
