/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:25 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:25 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	player_loc(t_cub *cub, int x, int y, char c)
{
	cub->t_cam.pos_x = (double)x + 0.5;
	cub->t_cam.pos_y = (double)y + 0.5;
	if (c == 'N')
	{
		cub->t_cam.dir_x = 0;
		cub->t_cam.dir_y = -1;
		cub->t_cam.plane_x = 1;
		cub->t_cam.plane_y = 0;
		return (1);
	}
	if (c == 'S')
	{
		cub->t_cam.dir_x = 0;
		cub->t_cam.dir_y = 1;
		cub->t_cam.plane_x = -1;
		cub->t_cam.plane_y = 0;
		return (1);
	}
	return (0);
}

int	player_loc2(t_cub *cub, int x, int y, char c)
{
	cub->t_cam.pos_x = (double)x + 0.5;
	cub->t_cam.pos_y = (double)y + 0.5;
	if (c == 'W')
	{
		cub->t_cam.dir_x = -1;
		cub->t_cam.dir_y = 0;
		cub->t_cam.plane_x = 0;
		cub->t_cam.plane_y = -1;
		return (1);
	}
	if (c == 'E')
	{
		cub->t_cam.dir_x = 1;
		cub->t_cam.dir_y = 0;
		cub->t_cam.plane_x = 0;
		cub->t_cam.plane_y = 1;
		return (1);
	}
	return (0);
}

char	location_init(char cmap, int i, int j, t_cub *cub)
{
	if (cmap == 'E' && player_loc2(cub, j, i, cmap))
		cmap = '0';
	else if (cmap == 'W' && player_loc2(cub, j, i, cmap))
		cmap = '0';
	else if (cmap == 'N' && player_loc(cub, j, i, cmap))
		cmap = '0';
	else if (cmap == 'S' && player_loc(cub, j, i, cmap))
		cmap = '0';
	else
		cmap = '1';
	return (cmap);
}
