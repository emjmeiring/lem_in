/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomeirin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:49:55 by jomeirin          #+#    #+#             */
/*   Updated: 2016/07/19 14:49:58 by jomeirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**ft_remalloc(char **farm_layout, int *size)
{
	int		i;
	char	**new_space;
	
	i = 0;
	new_space = (char **)malloc(sizeof(char *) * (*size) * 2);
	while (farm_layout[i])
	{
		new_space[i] = farm_layout[i];
		i++;
	}
	*size += *size;
	ft_memdel((void **)farm_layout);
	return (new_space);
}

char	**read_farm()
{
	int		i;
	int		nbytes;
	int		farm_size;
	char	*line;
	char	**farm_layout;
	
	i = 0;
	nbytes = 0;
	farm_size = 2000;
	line = (char *)malloc(sizeof(char) * 20);
	farm_layout = (char **)malloc(sizeof(char *) * farm_size);
					//needs to tested while loop
	while (get_next_line(0, &line))
	{
		if (!(*line == '#' && line[1] != '#'))
		{
			farm_layout[i] = ft_strdup(line);
			i++;
			if (i >= farm_size)
				farm_layout = ft_remalloc(farm_layout, &farm_size);
		}
	}
	ft_memdel((void **)&line);
	return (farm_layout);
}