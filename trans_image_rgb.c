/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_image_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:47 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:47 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

char	**skip_spaces(t_cub *cub)
{
	char	**temp_map;
	int		j;
	int		i;

	j = 0;
	i = 0;
	temp_map = cub->map;
	while (temp_map[i])
	{
		j = 0;
		while (temp_map[i][j] && (temp_map[i][j] == ' ' || \
			temp_map[i][j] == '\t' || temp_map[i][j] == '\n'))
			j++;
		if (temp_map[i][j])
			return (temp_map + j);
		i++;
	}
	return (cub->map);
}

void	trans_image_rgb(t_cub *cub)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	cub->map = skip_spaces(cub);
	while (cub->map[i])
	{
		if (cub->map[i])
			top_map_check(cub, i);
		i++;
	}
}
