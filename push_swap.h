/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:20:53 by oait-bou          #+#    #+#             */
/*   Updated: 2024/02/18 20:20:57 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				data;
	struct t_node	*next;
}					t_node;

size_t				ft_strlen(char *str);
t_node				*ft_lstlast(t_node *lst);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_back(t_node **lst, t_node *new);
int					check_sorted(t_node *a);
int					ft_lstsize(t_node *list);
void				sort_three(t_node **n);
void				push_b_to_a(t_node **stak_b, t_node **stak_a);
void				sa(t_node **p);
void				pb(t_node **head, t_node **p);
void				pa(t_node **head, t_node **p);
void				rb(t_node **head);
void				rrb(t_node **head);
void				ra(t_node **head);
void				rra(t_node **head);
void				rr(t_node **head, t_node **head1);
void				rrr(t_node **head, t_node **head1);
void				sort_it(t_node **stak_a, t_node **stak_b);
int					min(t_node *head);
int					best_move_to_b(t_node *stak_a, t_node *stak_b, int indx_b);
int					ft_index(t_node *b, int data);
void				check_push(t_node **stac_a, t_node **stac_b, int data,
						int b);
char				**ft_split(char *s, char c);
char				*ft_strjoin(char *s1, char *s2);
long				ft_atoi(const char *str);
t_node				*ft_lstnew(int data);
t_node				*apend_t_node(char **av);
void				ft_free(t_node **head);
int					cheack_vid_av(char **av);
void				check_dabel(t_node **haed);
#endif
