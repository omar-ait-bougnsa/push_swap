/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:15:38 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/10 21:15:47 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;
	int		j;

	i = start;
	j = 0;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0' && len > 0)
	{
		ptr[j] = s[i];
		i++;
		j++;
		len--;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;
	size_t	lens;

	j = 0;
	lens = 0;
	if (!s)
		return (NULL);
	while (s[lens])
		lens++;
	if (len > lens - start)
		len = lens - start;
	if (lens <= start)
	{
		ptr = malloc(1 * sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[j] = '\0';
		return (ptr);
	}
	ptr = ft_sub(s, start, len);
	return (ptr);
}

static int	cont_w(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	if (!str)
		return (0);
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	p = (char **)malloc((cont_w(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (s != NULL && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = 0;
		while (s[i] != c && s[i] != '\0' && j++ >= 0)
			i++;
		p[n++] = ft_substr(s, i - j, j);
	}
	free(s);
	p[n] = NULL;
	return (p);
}
