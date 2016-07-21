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
/*
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

int		ft_is_sum_c(char *what, char c)
{
	while (*what)
	{
		if (*what == c)
			return (1);
		what++;
	}
	return (0);
}

t_room	*find_start_end(char **farm_layout,char **room_specs, char *room)
{
	int i;
	int room_stat;
	t_room	*my_farm;

	i = -1;
	my_farm = NULL;
	if (room[1] == 's')
		room_stat = 1;
	else room_stat = 2;
	while (farm_layout[++i]) 
	{
		if (farm_layout[i][0] == '#')
		{
			if (ft_strcmp(&farm_layout[i][1], room) == 0)
			{
				room_specs = ft_strsplit(farm_layout[++i], ' ');
				my_farm = add_room(room_specs, room_stat);
			}
		}
	}
	if (!(my_farm))
	{
		write(1, "ERROR: why u not specify a #", 28);
		write(1, room, ft_strlen(room));
		write(1, " room, IDIOT!!GOSH\n", 19);
		exit(0);
	}
	return (my_farm); 
}

int		get_number_of_ant(char *farm_layout)
{
	if (ft_isdigit(farm_layout[0]))
		return (ft_atoi(farm_layout));
	else
	{
		write(1, "ERROR:why u not specify the number of ant,IDIOT!!GOSH\n", 56);
		exit(0);
	}
}

t_room	*populate_farm(char **farm_layout, t_ants *my_ants)
{
	int		i;
	char	**room_specs;
	t_room	*my_farm;
	t_room	*runner;
	t_room	*last_room;

	i = -1;
	room_specs = NULL;
	my_ants->at_start = get_number_of_ant(farm_layout[++i]);
	
	my_farm = find_start_end(&farm_layout[i], room_specs, "#start");
	last_room = find_start_end(&farm_layout[i], room_specs, "#end");
	my_farm->ant_stat = my_ants->at_start;
	runner = my_farm;
	i = 0;
	while (farm_layout[++i])
	{
		if (farm_layout[i][0] == '#')
			i += 2;
		if (ft_is_sum_c(farm_layout[i], ' '))
		{
			room_specs = ft_strsplit(farm_layout[i], ' ');
			runner->next = add_room(room_specs, 0);
			runner = runner->next;
		}
		else
		{
			if (ft_is_sum_c(farm_layout[i], '-'))
			{
				//while (farm_layout[i])
				//{
				//	set_links(farm_layout[i]);
				//}
				write(1, "awesome", 7);
			}
		}
	}
	runner->next = last_room;
	return (my_farm);
}
*/

void	set_weights(t_room *room, int weight)
{
	int i;
	
	i = -1;
	if (room->weight > weight)
		return ;
	room->weight = weight;
	while (room->tubes[++i])
		set_weights(room->tubes[i], weight - 1);
}

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
	printf("____%d_____", i);
	set_weights(runner, i);

	
	
	i = -1;
	while (farm_layout[++i])
		printf("%s\n", farm_layout[i]);
	runner = my_farm;
	while (runner)
	{
		i = -1;
		printf("\nn-%s :w-%d :s/e-%d :a-%d :x-%d :y-%d", runner->name, runner->weight, runner->s_e_room, runner->ant_stat, runner->x, runner->y);
		while (runner->tubes[++i])
			printf(" %d(%s) ", i, runner->tubes[i]->name);
		runner = runner->next;
	}
	printf("\n");
	return (0);
}
