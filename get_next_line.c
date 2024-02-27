/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:29 by oait-bou          #+#    #+#             */
/*   Updated: 2023/12/04 16:54:38 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sorted(t_node *head)
{
	int	i;

	while (head->next != NULL)
	{
		i = head->next->data;
		if (head->data > i)
			return (1);
		head = head->next;
	}
	return (0);
}

char	*chek_rest(char *str)
{
	int		i;
	int		b;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	b = ft_strlen(str) - i;
	str2 = malloc((b + 1) * sizeof(char));
	i++;
	while (j < b)
	{
		str2[j++] = str[i++];
	}
	str2[b] = '\0';
	return (str2);
}

char	*ft_free1(char *tr)
{
	free(tr);
	return (NULL);
}

char	*ft_read_line(int fd, char *tr)
{
	char	*buf;
	ssize_t	p;

	p = 1;
	buf = malloc(((size_t)(BUFFER_SIZE)) + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	while (p > 0 && check_line(tr) != 1)
	{
		p = read(fd, buf, BUFFER_SIZE);
		if (p > 0)
		{
			buf[p] = '\0';
			tr = ft_strjoin1(tr, buf);
		}
	}
	free(buf);
	if (p == -1)
		return (ft_free1(tr));
	return (tr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tr;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	tr = (ft_read_line(fd, tr));
	if (tr == NULL || tr[0] == '\0')
	{
		free(tr);
		tr = NULL;
		return (NULL);
	}
	line = ft_line(tr);
	ptr = chek_rest(tr);
	free(tr);
	tr = ptr;
	return (line);
}
