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
	if (!line)
		exit(0);
	if (!ft_strcmp(line, "1"))
	{
		alum->player = 1;
		ft_printf("You've chosen AI.\n");
	}
	else
	{
		alum->player = 2;
		ft_printf("You've chosen other player.\n");
	}
	free(line);
}

int		check_string(char *line)
{
	int i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (1);
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

	// max = get_max(alum->head);
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

void	alum_init(struct s_alum *alum)
{
	alum->head = NULL;
	alum->tail = NULL;
	alum->player = 1;
	alum->length = 0;
	alum->max = 0;
}

void	ft_put_choice(int matches)
{
	if (matches == 1)
	{
		ft_printf("Only one match left on the last row. You can only ");
		ft_printf("ask to remove 1 match\n");
	}
	else if (matches == 2)
	{
		ft_printf("2 matches left on the last row. How many matches");
		ft_printf(" do you want to remove? (1 or 2)\n");
	}
	else if (matches >= 3)
	{
		ft_printf("%d", matches);
		ft_printf(" matches left on the last row. How many matches ");
		ft_printf("do you want to remove? (1 to 3)\n");
	}
}

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

void	play_against_ai(struct s_alum *alum)
{
	char	*line;
	int		value;

	ft_printf("------The game begins!-----\n");
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
			alum->tail->number -= value;
			if (alum->tail->number == 0)
				delete_node(alum);

		}
		free(line);
	}
}

void	play_against_person(struct s_alum *alum)
{
	ft_printf("------The game begins!-----\n");
	print_list(alum);
	// ft_printf("NUM: %d\n", alum->tail->number);	
}

int main(int argc, char **argv)
{
	struct s_alum *alum;

	argc > 2 ? ft_usage() : 0;
	alum = (t_alum*)malloc(sizeof(t_alum));
	alum_init(alum);
	if (!argv[1])
	{
		parse_map_from_stdin(alum);
		versus_who(alum);
		alum->max = get_max(alum->head);
		if (alum->player == 1)
			play_against_ai(alum);
		else if (alum->player == 2)
			play_against_person(alum);
		else
			ft_error("Error. Wrong player.");
	}
	else
	{
		parse_map_from_file(alum, argv[1]);
		versus_who(alum);
		alum->max = get_max(alum->head);
		if (alum->player == 1)
			play_against_ai(alum);
		else if (alum->player == 2)
			play_against_person(alum);
		else
			ft_error("Error. Wrong player.");
	}
	ft_printf("\n");
	system("leaks alum1");
	return (0);
}
