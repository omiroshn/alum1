/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omiroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 22:17:37 by omiroshn          #+#    #+#             */
/*   Updated: 2018/10/21 22:17:38 by omiroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	alum_init(struct s_alum *alum)
{
	alum->head = NULL;
	alum->tail = NULL;
	alum->player = 1;
	alum->length = 0;
	alum->max = 0;
	alum->bots_value = 0;
}
