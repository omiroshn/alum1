/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 22:18:36 by omiroshn          #+#    #+#             */
/*   Updated: 2018/10/21 22:18:37 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	take_from_last_line(struct s_alum *alum)
{
	int num;

	num = alum->tail->number;
	if (num % 4 == 1)
		alum->bots_value = 1;
	else if (num > 5 && num % 4 > 1)
		alum->bots_value = num - (num - (num % 4 - 1));
	else if (num > 5 && num % 4 == 0)
		alum->bots_value = 3;
	else if (num > 1 && num < 5)
		alum->bots_value = num - 1;
	else
		alum->bots_value = 1;
}

void	bots_turn(struct s_alum *alum)
{
	int num;

	num = alum->tail->number;
	if (alum->length == 1)
		take_from_last_line(alum);
	else if (num > 5)
		alum->bots_value = 3;
	else if (num == 5)
		alum->bots_value = 1;
	else if (num == 2)
		alum->bots_value = 1;
	else if (num == 3)
		alum->bots_value = 2;
	else if (num == 4)
		alum->bots_value = 3;
	else
		alum->bots_value = 1;
	print_list(alum);
	ft_printf("\033[91m--Computer plays his turn : removes ");
	if (alum->bots_value == 1)
		ft_printf("%d match--\033[0m\n", alum->bots_value);
	else
		ft_printf("%d matches--\033[0m\n", alum->bots_value);
	alum->tail->number -= alum->bots_value;
}

int		make_move(struct s_alum *alum, int value)
{
	alum->tail->number -= value;
	if (alum->tail->number == 0)
		delete_node(alum);
	bots_turn(alum);
	if (alum->tail->number == 0)
		delete_node(alum);
	if (alum->length == 0 && alum->tail->number == 0)
	{
		ft_printf("\033[1;32m------You  Win!------\n\033[0m");
		return (0);
	}
	else if (alum->length == 0)
	{
		ft_printf("\033[1;32m------Computer Wins------\n\033[0m");
		return (0);
	}
	return (1);
}

void	play_against_ai(struct s_alum *alum)
{
	char	*line;
	int		value;

	ft_printf("\033[1;32m------The game begins!-----\n\033[0m");
	while (alum->head->number > 0)
	{
		print_list(alum);
		ft_put_choice(alum->tail->number);
		if (!(get_next_line(0, &line)))
			break ;
		value = ft_atoi(line);
		if (value < 1 || value > 3 || value > alum->tail->number)
			ft_put_choice(alum->tail->number);
		else
		{
			if (make_move(alum, value) == 0)
				break ;
		}
		free(line);
	}
	free(line);
}
