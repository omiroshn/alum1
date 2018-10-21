/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   person.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 22:18:47 by omiroshn          #+#    #+#             */
/*   Updated: 2018/10/21 22:18:48 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		turn1(struct s_alum *alum, char **line)
{
	int		value;

	print_list(alum);
	ft_put_choice(alum->tail->number);
	if (!(get_next_line(0, line)))
		return (0);
	value = ft_atoi(*line);
	if (value < 1 || value > 3 || value > alum->tail->number)
		ft_put_choice(alum->tail->number);
	else
	{
		alum->tail->number -= value;
		if (alum->tail->number == 0)
			delete_node(alum);
		if (alum->length == 0 && alum->tail->number == 0)
		{
			ft_printf("\033[1;33m------Player 2 wins!------\n\033[0m");
			return (0);
		}
	}
	free(*line);
	return (1);
}

int		turn2(struct s_alum *alum, char **line)
{
	int		value;

	print_list(alum);
	ft_put_choice(alum->tail->number);
	if (!(get_next_line(0, line)))
		return (0);
	value = ft_atoi(*line);
	if (value < 1 || value > 3 || value > alum->tail->number)
		ft_put_choice(alum->tail->number);
	else
	{
		alum->tail->number -= value;
		if (alum->tail->number == 0)
			delete_node(alum);
		if (alum->length == 0 && alum->tail->number == 0)
		{
			ft_printf("\033[1;33m------Player 1 wins!------\n\033[0m");
			return (0);
		}
	}
	free(*line);
	return (1);
}

void	play_against_person(struct s_alum *alum)
{
	char	*line;

	ft_printf("\033[1;32m------The game begins!-----\n\033[0m");
	while (alum->head->number > 0)
	{
		ft_printf("\033[1;32m--Player 1 plays his turn--\n\033[0m");
		if (turn1(alum, &line) == 0)
			break ;
		ft_printf("\033[1;34m--Player 2 plays his turn--\n\033[0m");
		if (turn2(alum, &line) == 0)
			break ;
	}
	free(line);
}
