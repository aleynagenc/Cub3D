/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:10 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:11 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static void	rotate_cam(t_cub *cub, t_cam *cam)
{
	double	old_dir_y;
	double	old_plane_y;

	old_dir_y = cam->dir_y;
	cam->dir_y = cam->dir_y * cos(-cub->g_plyr.rotspd) - \
		cam->dir_x * sin(-cub->g_plyr.rotspd);
	cam->dir_x = old_dir_y * sin(-cub->g_plyr.rotspd) + \
		cam->dir_x * cos(-cub->g_plyr.rotspd);
	old_plane_y = cam->plane_y;
	cam->plane_y = cam->plane_y * cos(-cub->g_plyr.rotspd) - cam->plane_x \
		* sin(-cub->g_plyr.rotspd);
	cam->plane_x = old_plane_y * sin(-cub->g_plyr.rotspd) + cam->plane_x \
		* cos(-cub->g_plyr.rotspd);
}

static void	key_move2(t_cub *cub, t_cam *cam, int **map)
{
	if (cub->kbd.l || cub->kbd.r)
	{
		rotate_cam(cub, cam);
	}
	if (cub->kbd.d)
	{
		if (!map[(int)(cam->pos_y + cam->plane_y * cub->g_plyr.movespd)]
			[(int)cam->pos_x])
			cam->pos_y += cam->plane_y * cub->g_plyr.movespd;
		if (!map[(int)cam->pos_y]
			[(int)(cam->pos_x + cam->plane_x * cub->g_plyr.movespd)])
			cam->pos_x += cam->plane_x * cub->g_plyr.movespd;
	}
	if (cub->kbd.a)
	{
		if (!map[(int)(cam->pos_y - cam->plane_y * cub->g_plyr.movespd)]
			[(int)cam->pos_x])
			cam->pos_y -= cam->plane_y * cub->g_plyr.movespd;
		if (!map[(int)cam->pos_y]
			[(int)(cam->pos_x - cam->plane_x * cub->g_plyr.movespd)])
			cam->pos_x -= cam->plane_x * cub->g_plyr.movespd;
	}
}

void	key_move(t_cub *cub, t_cam *cam)
{
	int	**map;

	map = cub->i_map;
	if (cub->kbd.w)
	{
		if (cub->g_plyr.movespd == 0.03)
			cub->g_plyr.movespd = 0.04;
		if (!map[(int)(cam->pos_y + cam->dir_y * cub->g_plyr.movespd)] \
		[(int)cam->pos_x])
			cam->pos_y += cam->dir_y * cub->g_plyr.movespd;
		if (!map[(int)cam->pos_y][(int)(cam->pos_x + cam->dir_x \
			* cub->g_plyr.movespd)])
			cam->pos_x += cam->dir_x * cub->g_plyr.movespd;
	}
	if (cub->kbd.s)
	{
		if (!map[(int)(cam->pos_y - cam->dir_y * cub->g_plyr.movespd)] \
			[(int)cam->pos_x])
			cam->pos_y -= cam->dir_y * cub->g_plyr.movespd;
		if (!map[(int)cam->pos_y][(int)(cam->pos_x - cam->dir_x \
			* cub->g_plyr.movespd)])
			cam->pos_x -= cam->dir_x * cub->g_plyr.movespd;
	}
	key_move2(cub, cam, map);
}
