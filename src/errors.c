/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 22:13:24 by omiroshn          #+#    #+#             */
/*   Updated: 2018/10/21 22:13:25 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	ft_usage(void)
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

int		check_string(char *line)
{
	int i;

	i = -1;
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (1);
}
