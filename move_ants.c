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

int		get_best_tube(t_room *my_farm)
{
	int i;
	int max_weight;
	int max_i;

	i = -1;
	max_weight = 0;
	max_i = 0;
	while (my_farm->tubes[++i])
	{
		if (my_farm->tubes[i]->weight > max_weight)
		{
			max_weight = my_farm->tubes[i]->weight;
			max_i = i;
		}
	}
	return (max_i);
}

int		move_ants_onwards(t_room *room)
{
	int right_tube;

	right_tube = get_best_tube(room);
	if (room->tubes[right_tube]->ant_stat > 0 && !(room->tubes[right_tube]->s_e_room == 2))
		move_ants_onwards(room->tubes[right_tube]);
	if ((room->tubes[right_tube]->ant_stat == 0))
	{
		room->tubes[right_tube]->ant_stat += room->ant_stat;
		printf("L%d-%s ", room->ant_stat, room->tubes[right_tube]->name);
		room->ant_stat -= room->ant_stat;
		return (1);
	}
	else if (room->tubes[right_tube]->s_e_room == 2)
	{
		room->tubes[right_tube]->ant_stat += 1;
		printf("L%d-%s ", room->ant_stat, room->tubes[right_tube]->name);
		room->ant_stat -= room->ant_stat;
		return (1);
	}
	printf("ass");
	return (0);
}

void	clear_farm(t_room *my_farm)
{
	t_room *runner;

	runner = my_farm;
	while (runner->next)
	{
		if (runner->ant_stat > 0)
			move_ants_onwards(runner);
		runner = runner->next;
	}
}

int		move_dem_ants(t_room *my_farm)
{
	int num_ant;
	int right_tube;

	num_ant = 1;
	right_tube = get_best_tube(my_farm);
	while (my_farm->ant_stat > 0)
	{
		if (my_farm->tubes[right_tube]->ant_stat == 0)
		{
			my_farm->tubes[right_tube]->ant_stat += num_ant;
			my_farm->ant_stat -= 1;
			printf("L%d-%s ", num_ant, my_farm->tubes[right_tube]->name);
			num_ant++;
			printf("\n");
		}
		else
			move_ants_onwards(my_farm->tubes[right_tube]);
	}
	clear_farm(my_farm);
	printf("\n");
	
	return (1);
}
