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

void	ft_usage()
{
	ft_printf("./alum1 [FILE]\n");
	system("leaks alum1");
	exit(1);
}

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	system("leaks alum1");
	exit(-1);
}

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
	if (!ft_strcmp(line, "1"))
		alum->player = 1;
	else
		alum->player = 2;
	free(line);
}

void	parse_map_from_stdin(struct s_alum *alum)
{
	char *line;

	while (get_next_line(0, &line) && ft_strcmp(line, ""))
	{
		ft_printf("CHIRIK: %s\n", line);
		free(line);
	}
	free(line);
}

void	ft__read()
{
	ft_printf("Enter number of matches (1 to 10000) per row (Enter for each row).\n");
	ft_printf("Press Enter when you are finished.\n");
}

int main(int argc, char **argv)
{
	struct s_alum *alum;

	argc > 2 ? ft_usage() : 0;
	alum = (t_alum*)malloc(sizeof(t_alum));
	if (!argv[1])
	{
		versus_who(alum);
		parse_map_from_stdin(alum);
	}
	else
	{
		versus_who(alum);
	}
	ft_printf("\n");
	system("leaks alum1");
	return (0);
}
