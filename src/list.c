/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 22:19:35 by omiroshn          #+#    #+#             */
/*   Updated: 2018/10/21 22:19:36 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	delete_node(struct s_alum *alum)
{
	int		i;
	t_node	*head;

	head = alum->head;
	alum->length--;
	i = -1;
	while (++i < alum->length - 1)
		head = head->next;
	alum->tail = head;
}

int		get_max(t_node *head)
{
	int		max;
	t_node	*step;

	max = 0;
	step = head;
	while (step != NULL)
	{
		if (step->number > max)
			max = step->number;
		step = step->next;
	}
	return (max);
}

void	print_list(t_alum *alum)
{
	int		j;
	int		i;
	int		max;
	t_node	*step;

	max = alum->max;
	step = alum->head;
	j = -1;
	while (step != NULL && ++j < alum->length)
	{
		if (step->number != max)
			ft_printf("%*s", (max - step->number) / 2, "");
		i = -1;
		while (++i < step->number)
			ft_printf("|");
		ft_printf("\n");
		step = step->next;
	}
}

void	enqueue(struct s_alum *alum, int num)
{
	t_node *node;

	node = (t_node*)malloc(sizeof(t_node));
	node->number = num;
	node->next = NULL;
	if (alum->tail == NULL)
	{
		alum->tail = node;
		alum->head = alum->tail;
	}
	else
	{
		alum->tail->next = node;
		alum->tail = alum->tail->next;
	}
	alum->length++;
}
