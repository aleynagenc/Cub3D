/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmap_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:06 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:06 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static int	gmap_size(t_cub *cub)
{
	int	i;
	int	j;
	int	tab;
	int	index;

	i = 0;
	j = 0;
	tab = 0;
	index = 0;
	while (cub->map[i])
	{
		if (j > index)
			index = j;
		if (i > j)
			index = i;
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '\t')
				tab += 8;
			j++;
		}
		i++;
	}
	return (index + tab);
}

static void	gmap_int2(t_cub *cub, int i, int j, int **int_map)
{
	int		index;
	char	**cmap;

	cmap = cub->map;
	while (cmap[i])
	{
		j = 0;
		while (cmap[i][j])
		{
			if (cmap[i][j] && (cmap[i][j] == 'N' || cmap[i][j] == 'S' || \
				cmap[i][j] == 'W' || cmap[i][j] == 'E' || cmap[i][j] == ' '))
				cmap[i][j] = location_init(cmap[i][j], i, j, cub);
			index = ft_atoic(cmap[i][j]);
			int_map[i][j] = index;
			j++;
		}
		i++;
	}
}

void	gmap_int(t_cub *cub)
{
	int	i;
	int	j;
	int	map_size;
	int	**int_map;

	i = 0;
	j = 0;
	map_size = gmap_size(cub);
	int_map = (int **)malloc(sizeof(int *) * (map_size + 1));
	while (j < map_size)
	{
		int_map[j] = malloc(sizeof(int *) * (map_size + 1));
		j++;
	}
	gmap_int2(cub, i, j, int_map);
	cub->i_map = int_map;
}
