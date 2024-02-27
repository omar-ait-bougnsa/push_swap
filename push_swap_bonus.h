/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:14:50 by oait-bou          #+#    #+#             */
/*   Updated: 2023/12/10 11:14:56 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_node
{
	int				data;
	struct t_node	*next;
}					t_node;

t_node				*apend_t_node(char **av);
char				*ft_strjoin1(char *s1, char *s2);
char				*get_next_line(int fd);
void				*ft_memcpy(void *dest, const void *src, size_t size);
size_t				ft_strlen(char *str);
char				*ft_line(char *str);
int					check_line(char *str);
void				rotate(t_node **head);
void				reverse(t_node **head);
int					cheack_vid_av(char **av);
void				check_dabel(t_node **haed);
char				**ft_split(char *s, char c);
char				*ft_strjoin(char *s1, char *s2);
long				ft_atoi(const char *str);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_back(t_node **lst, t_node *new);
void				push(t_node **head, t_node **p);
void				swap(t_node **p);
int					check_sorted(t_node *head);
void				ft_free(t_node **head);
char				*ft_strcpy(char *s1, char *s2);
#endif
