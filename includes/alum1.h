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

#include "libft.h"

typedef struct		s_node
{
	int				number;
	struct s_node	*next;
}					t_node;

typedef struct	s_alum
{
	t_node	*head;
	t_node	*tail;
	int		max;
	int		length;
	short	player;
}				t_alum;

#endif
