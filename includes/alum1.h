/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:06:25 by omiroshn          #+#    #+#             */
/*   Updated: 2018/10/19 21:06:26 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "libft.h"

typedef struct		s_node
{
	int				number;
	struct s_node	*next;
}					t_node;

typedef struct		s_alum
{
	t_node	*head;
	t_node	*tail;
	int		max;
	int		bots_value;
	int		length;
	short	player;
}					t_alum;

void				ft_usage(void);
void				ft_error(char *msg);
int					check_string(char *line);
void				alum_init(struct s_alum *alum);
void				delete_node(struct s_alum *alum);
int					get_max(t_node *head);
void				print_list(t_alum *alum);
void				enqueue(struct s_alum *alum, int num);
void				take_from_last_line(struct s_alum *alum);
void				bots_turn(struct s_alum *alum);
int					make_move(struct s_alum *alum, int value);
void				play_against_ai(struct s_alum *alum);
int					turn1(struct s_alum *alum, char **line);
int					turn2(struct s_alum *alum, char **line);
void				play_against_person(struct s_alum *alum);
void				ft_put_choice(int matches);

#endif
