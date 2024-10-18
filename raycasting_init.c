/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:42 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:43 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	raycasting_init(t_cub *cub)
{
	cub->g_plyr.cam_x = (2 * (double)cub->x / (double)WIDTH) - 1;
	cub->g_plyr.loc_x = cub->t_cam.pos_x;
	cub->g_plyr.loc_y = cub->t_cam.pos_y;
	cub->g_plyr.dir_x = cub->t_cam.dir_x + \
		cub->t_cam.plane_x * cub->g_plyr.cam_x;
	cub->g_plyr.dir_y = cub->t_cam.dir_y + \
		cub->t_cam.plane_y * cub->g_plyr.cam_x;
	cub->g_plyr.map_x = (int)cub->g_plyr.loc_x;
	cub->g_plyr.map_y = (int)cub->g_plyr.loc_y;
	cub->g_plyr.ddist_x = sqrt(1 + (cub->g_plyr.dir_y * cub->g_plyr.dir_y) / \
		(cub->g_plyr.dir_x * cub->g_plyr.dir_x));
	cub->g_plyr.ddist_y = sqrt(1 + (cub->g_plyr.dir_x * cub->g_plyr.dir_x) / \
		(cub->g_plyr.dir_y * cub->g_plyr.dir_y));
	cub->g_plyr.wall_pass = 0;
}

void	raycasting_player_angle(t_cub *cub)
{
	if (cub->g_plyr.dir_x < 0)
	{
		cub->g_plyr.sx = -1;
		cub->g_plyr.sdist_x = (cub->g_plyr.loc_x - cub->g_plyr.map_x) * \
			cub->g_plyr.ddist_x;
	}
	else
	{
		cub->g_plyr.sx = 1;
		cub->g_plyr.sdist_x = (cub->g_plyr.map_x + 1 - cub->g_plyr.loc_x) * \
			cub->g_plyr.ddist_x;
	}
	if (cub->g_plyr.dir_y < 0)
	{
		cub->g_plyr.sy = -1;
		cub->g_plyr.sdist_y = (cub->g_plyr.loc_y - cub->g_plyr.map_y)
			* cub->g_plyr.ddist_y;
	}
	else
	{
		cub->g_plyr.sy = 1;
		cub->g_plyr.sdist_y = (cub->g_plyr.map_y + 1 - cub->g_plyr.loc_y)
			* cub->g_plyr.ddist_y;
	}
}

void	raycasting_wall_pass(t_cub *cub)
{
	while (cub->g_plyr.wall_pass == 0)
	{
		if (cub->g_plyr.sdist_x < cub->g_plyr.sdist_y)
		{
			cub->g_plyr.sdist_x += cub->g_plyr.ddist_x;
			cub->g_plyr.map_x += cub->g_plyr.sx;
			cub->g_plyr.wall_dir = 0;
		}
		else
		{
			cub->g_plyr.sdist_y += cub->g_plyr.ddist_y;
			cub->g_plyr.map_y += cub->g_plyr.sy;
			cub->g_plyr.wall_dir = 1;
		}
		if (cub->i_map[(int)cub->g_plyr.map_y] \
			[(int)cub->g_plyr.map_x] == 1)
		{
			cub->g_plyr.wall_pass = 1;
		}
	}
	raycasting_wall_dist(cub);
}

void	raycasting_wall_dist(t_cub *cub)
{
	if (cub->g_plyr.wall_dir == 0)
	{
		cub->g_plyr.wall_dist = fabs((cub->g_plyr.map_x - cub->t_cam.pos_x \
			+ (1 - cub->g_plyr.sx) / 2) / cub->g_plyr.dir_x);
	}
	else
	{
		cub->g_plyr.wall_dist = fabs((cub->g_plyr.map_y - cub->t_cam.pos_y \
			+ (1 - cub->g_plyr.sy) / 2) / cub->g_plyr.dir_y);
	}
}

void	raycasting_wall_orien(t_cub *cub)
{
	if (cub->g_plyr.wall_dir == 0)
	{
		cub->g_plyr.wall_x = cub->g_plyr.loc_y + cub->g_plyr.wall_dist \
			* cub->g_plyr.dir_y;
	}
	else
	{
		cub->g_plyr.wall_x = cub->g_plyr.loc_x + cub->g_plyr.wall_dist \
			* cub->g_plyr.dir_x;
	}
	cub->g_plyr.wall_x -= floor(cub->g_plyr.wall_x);
	cub->img.img_x = (int)(cub->g_plyr.wall_x * IMG_WIDTH);
	if (cub->g_plyr.wall_dir == 0 && cub->g_plyr.dir_x > 0)
		cub->img.img_x = IMG_WIDTH - cub->img.img_x - 1;
	if (cub->g_plyr.wall_dir == 1 && cub->g_plyr.dir_y < 0)
		cub->img.img_x = IMG_WIDTH - cub->img.img_x - 1;
}
