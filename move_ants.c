/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 17:22:37 by jomeirin          #+#    #+#             */
/*   Updated: 2016/07/21 17:22:40 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		move_dem_ants(t_room *room)
{
	int i;

	while (room->ant_stat > 0)
	{
		i = -1;
		while (room->tubes[++i])
		{
			if (room->tubes[i]->ant_stat == 0 || room->tubes[i]->s_e_room == 2)
			{
				room->tubes[i]->ant_stat += 1;
				room->ant_stat -= 1;
			}
			else
			{
				move_dem_ants(room->tubes[i]);
				i--;
			}
		}
	}
	return (1);
}
