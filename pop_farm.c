#include "lem_in.h"

t_room	*add_room(char **room_specs, int room_stat)
{
	t_room	*a_room;
	int		i;

	i = -1;
	if (!room_specs[0] || !room_specs[1][0] || !room_specs[2])
	{
		write(1, "ERROR: why u not specify a valid room, IDIOT!!GOSH\n", 51);
		//exit(0);
	}
	a_room = (t_room *)malloc(sizeof(t_room));
	a_room->name = room_specs[0];
	a_room->weight = 0;
	a_room->s_e_room = room_stat;
	a_room->ant_stat = 0;
	a_room->x = ft_atoi(room_specs[1]);
	a_room->y = ft_atoi(room_specs[2]);
	a_room->next = NULL;
	a_room->tubes = (t_room **)malloc(sizeof(t_room *) * 30);
	while (++i < 30)
		a_room->tubes[i] = NULL;
	free(*(room_specs + 1));
	free(*(room_specs + 2));
	return (a_room);
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

void	set_links(t_room *my_farm, char *farm_layout)
{
	t_room	*from;
	t_room	*to;
	char	**rooms;
	int i;

	i = 0;
	from = NULL;
	rooms = ft_strsplit(farm_layout, '-');
	//printf("%s - %s\n", rooms[0], rooms[1]);
	if (!(from = find_room(my_farm, rooms[0])) || !(to = find_room(my_farm, rooms[1]) ))
	{
		write(1, "couldn't establish (1) link\n", 28);
		exit(0);
	}
	else
	{
		while (i < 30 && from->tubes[i])
			i++;
		from->tubes[i] = to;
		i = 0;
		while (i < 30 && to->tubes[i])
			i++;
		to->tubes[i] = from;
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
			i += 1;
		else if (ft_is_sum_c(farm_layout[i], ' '))
		{
			room_specs = ft_strsplit(farm_layout[i], ' ');
			runner->next = add_room(room_specs, 0);
			runner = runner->next;
		}
		else
		{
			if (ft_is_sum_c(farm_layout[i], '-'))
				runner->next = last_room;
			while (ft_is_sum_c(farm_layout[i], '-') && farm_layout[i])
			{
				//printf("lay : %s\n", farm_layout[i]);
				set_links(my_farm, farm_layout[i]);
				i++;
				//write(1, "awesome", 7);
			}
		}
	}
	
	return (my_farm);
}
