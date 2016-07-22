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

void	move_ants_onwards(t_room *room)
{
	int i;

	i = -1;
		while (room->tubes[++i])
		{
			if ((room->tubes[i]->ant_stat == 0 && room->weight <= room->tubes[i]->weight))
			{
				room->tubes[i]->ant_stat += room->ant_stat;
				printf("L%d-%s ", room->ant_stat, room->tubes[i]->name);
				room->ant_stat -= room->ant_stat;
				return ;
			}
			else if (room->s_e_room == 2)
			{
				room->tubes[i]->ant_stat += 1;
				printf("L%d-%s ", room->ant_stat, room->tubes[i]->name);
				room->ant_stat -= room->ant_stat;
				return ;
			}
		}
		if (!room->tubes[i])
		{
			i = -1;
			move_ants_onwards(room->tubes[i]);
			i++;
		}
}

int		move_dem_ants(t_room *room)
{
	int i;
	int num_ant;

	num_ant = 1;
	while (room->ant_stat > 36)
	{
		i = -1;
		while (room->tubes[++i])
		{
			if (room->tubes[i]->ant_stat == 0)
			{
				room->tubes[i]->ant_stat += num_ant;
				room->ant_stat -= 1;
				printf("L%d-%s ", num_ant, room->tubes[i]->name);
				num_ant++;
			}
			else
			{
				move_ants_onwards(room->tubes[i]);
				i--;
			}
		}
		printf("\n");
	}
	return (1);
}
