/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 13:06:44 by jomeirin          #+#    #+#             */
/*   Updated: 2016/07/19 13:06:46 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct		s_room
{
	char			*name;
	int				weight;
	int				s_e_room;
	int				ant_stat;
	int				x;
	int				y;
	struct s_room	*next;
	struct s_room	**tubes;
}					t_room;

typedef struct		s_ants
{
	int				at_start;
	int				at_end;
}					t_ants;

int			move_dem_ants(t_room *room);
char		**read_farm();
char		**ft_remalloc(char **farm_layout, int *size);
t_room		*add_room(char **room_specs, int room_stat);
int			ft_is_sum_c(char *what, char c);
t_room		*find_start_end(char **farm_layout,char **room_specs, char *room);
int			get_number_of_ant(char *farm_layout);
t_room		*find_room(t_room *my_farm, char *room);
void		set_links(t_room *my_farm, char *farm_layout);
t_room		*populate_farm(char **farm_layout, t_ants *my_ants);
void		set_weights(t_room *room, int weight);

#endif
