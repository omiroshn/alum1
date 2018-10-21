/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:06:13 by omiroshn          #+#    #+#             */
/*   Updated: 2018/10/19 21:06:14 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	versus_who(struct s_alum *alum)
{
	char *line;

	ft_printf("Welcome to Alum1!\n");
	ft_printf("Choose your opponent:\n1 - AI\n2 - Other person\n");
	while (get_next_line(0, &line)
		&& ft_strcmp(line, "1") && ft_strcmp(line, "2"))
	{
		ft_printf("Wrong, try again!\n");
		free(line);
	}
	if (!line)
		exit(0);
	if (!ft_strcmp(line, "1"))
	{
		alum->player = 1;
		ft_printf("\033[1;33mYou've chosen AI.\n\033[0m");
	}
	else
	{
		alum->player = 2;
		ft_printf("\033[1;33mYou've chosen other player.\n\033[0m");
	}
	free(line);
}

void	parse_map_from_stdin(struct s_alum *alum)
{
	char	*line;
	int		num;

	ft_printf("Enter number of matches (1 to 10000)");
	ft_printf(" per row (Enter for each row).\n");
	ft_printf("Press Enter when you are finished.\n");
	while (get_next_line(0, &line) && ft_strcmp(line, ""))
	{
		check_string(line) == 0 ? ft_error("ERROR. Number is wrong") : 0;
		num = ft_atoi(line);
		num < 1 ? ft_error("ERROR. Number is < than 1.") : 0;
		num > 10000 ? ft_error("ERROR. Number is > than 10000.") : 0;
		enqueue(alum, num);
		free(line);
	}
	if (alum->length == 0)
		ft_error("Error. Number of matches is 0.");
	free(line);
	alum->max = get_max(alum->head);
}

void	parse_map_from_file(struct s_alum *alum, char *path)
{
	int		fd;
	int		num;
	char	*line;

	if ((fd = open(path, O_RDONLY)) < 0 || read(fd, NULL, 0) < 0)
		ft_error("Error. Opening file.");
	while (get_next_line(fd, &line))
	{
		check_string(line) == 0 ? ft_error("ERROR. Number is wrong") : 0;
		num = ft_atoi(line);
		num < 1 ? ft_error("ERROR. Number is < than 1.") : 0;
		num > 10000 ? ft_error("ERROR. Number is > than 10000.") : 0;
		enqueue(alum, num);
		free(line);
	}
	if (alum->length == 0)
		ft_error("Error. Number of matches is 0.");
	free(line);
}

void	ft_put_choice(int matches)
{
	if (matches == 1)
	{
		ft_printf("Only \033[1;33mone\033[0m match left on the last row. ");
		ft_printf("You can only ask to remove 1 match\n");
	}
	else if (matches == 2)
	{
		ft_printf("\033[1;33m2\033[0m matches left on the last row. ");
		ft_printf("How many matches do you want to remove? (1 or 2)\n");
	}
	else if (matches >= 3)
	{
		ft_printf("\033[1;33m%d\033[0m", matches);
		ft_printf(" matches left on the last row. How many matches ");
		ft_printf("do you want to remove? (1 to 3)\n");
	}
}

int		main(int argc, char **argv)
{
	struct s_alum *alum;

	argc > 2 ? ft_usage() : 0;
	alum = (t_alum*)malloc(sizeof(t_alum));
	alum_init(alum);
	if (!argv[1])
		parse_map_from_stdin(alum);
	else
		parse_map_from_file(alum, argv[1]);
	versus_who(alum);
	alum->max = get_max(alum->head);
	if (alum->player == 1)
		play_against_ai(alum);
	else if (alum->player == 2)
		play_against_person(alum);
	else
		ft_error("Error. Wrong player.");
	system("leaks alum1");
	return (0);
}
