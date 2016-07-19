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

t_room	*add_room(char **room_specs, int room_stat)
{
	t_room	*a_room;
	
	if (!room_specs[0][0] || !room_specs[1][0] || !room_specs[2][0])
	{
		write(1, "ERROR: why u not specify a valid room, IDIOT!!GOSH\n", 51);
		exit(0);
	}
	a_room = (t_room *)malloc(sizeof(t_room));
	a_room->name = room_specs[0];
	a_room->weight = 0;
	a_room->s_e_room = room_stat;
	a_room->ant_stat = 0;
	a_room->x = ft_atoi(room_specs[1]);
	a_room->y = ft_atoi(room_specs[2]);
	a_room->next = NULL;
	return (a_room);
}

t_room	*populate_farm(char **farm_layout, t_ants *my_ants)
{
	int		i;
	char	**room_specs;
	t_room	*my_farm;
	t_room	*runner;

	i = -1;
	if (ft_isdigit(farm_layout[++i][0]))
		my_ants->at_start = ft_atoi(farm_layout[i]);
	else
	{
		write(1, "ERROR:why u not specify the number of ant,IDIOT!!GOSH\n", 56);
		exit(0);
	}
	while (farm_layout[++i] && (ft_strcmp(farm_layout[i], "##start") == 0))
	{
		room_specs = ft_strsplit(farm_layout[++i], ' ');
		my_farm = add_room(room_specs, 1);
		my_farm->ant_stat = my_ants->at_start;
	}
	if (!(my_farm->ant_stat))
	{
		write(1, "ERROR: why u not specify a start room, IDIOT!!GOSH\n", 51);
		exit(0);
	}
	else
	{
		runner = my_farm;
		i = 0;
	}
	while (farm_layout[++i])
	{
		if (farm_layout[i][0] == '#')
			i += 2;
		room_specs = ft_strsplit(farm_layout[i], ' ');
		runner->next = add_room(room_specs, 0);
	}
	return (my_farm);
}

int		main(void)
{
	t_room	*my_farm;
	t_ants	my_ants;
	char	**farm_layout;
	int		i;

	my_ants.at_start = 0;
	my_ants.at_end = 0;
	farm_layout = read_farm();
	my_farm = populate_farm(farm_layout, &my_ants);
	i = -1;
	
		//while (farm_layout[++i])
		//printf("%s\n", farm_layout[i]);
	return (0);
}
