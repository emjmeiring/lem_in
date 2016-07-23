/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:37:50 by jomeirin          #+#    #+#             */
/*   Updated: 2016/07/18 13:37:54 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_room	*my_farm;
	t_room	*runner;
	t_ants	my_ants;
	char	**farm_layout;
	int		i;

	my_ants.at_start = 0;
	my_ants.at_end = 0;
	farm_layout = read_farm();
	my_farm = populate_farm(farm_layout, &my_ants);
	i = 1;
	runner = my_farm;
	while (runner->next)
	{
		runner = runner->next;
		i++;
	}
	set_weights(runner, i);
	i = -1;
	while (farm_layout[++i])
		printf("%s\n", farm_layout[i]);
	printf("\n");
	move_dem_ants(my_farm);

	
	
	
	runner = my_farm;
	while (runner)
	{
		i = -1;
		printf("\nn-%s :w-%d :s/e-%d :a-%d :x-%d :y-%d", runner->name, runner->weight, runner->s_e_room, runner->ant_stat, runner->x, runner->y);
		while (runner->tubes[++i])
			printf("\t%d(%s) ", i, runner->tubes[i]->name);
		runner = runner->next;
	}
	printf("\n");
	return (0);
}
