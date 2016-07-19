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

char		**read_farm();
char		**ft_remalloc(char **farm_layout, int *size);

#endif
