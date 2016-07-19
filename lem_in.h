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

typedef struct		s_room
{
	int				wieght;
	int				s_e_room;
	int				ant_stat;
	int				x;
	int				y;
	struct s_room	*next;
	struct s_room	**links;
}					t_room;

#endif