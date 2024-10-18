/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_reset2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:54 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:53:55 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static void	camera_reset(t_cub *cub)
{
	cub->t_cam.pos_x = 0;
	cub->t_cam.pos_y = 0;
	cub->t_cam.dir_x = 0;
	cub->t_cam.dir_y = 0;
	cub->t_cam.plane_x = 0;
	cub->t_cam.plane_y = 0;
	cub->t_cam.display = 1;
}

static void	player_reset(t_cub *cub)
{
	cub->g_plyr.cam_x = 0;
	cub->g_plyr.cam_y = 0;
	cub->g_plyr.ddist_x = 0;
	cub->g_plyr.ddist_y = 0;
	cub->g_plyr.dir_x = 0;
	cub->g_plyr.dir_y = 0;
	cub->g_plyr.loc_x = 0;
	cub->g_plyr.loc_y = 0;
	cub->g_plyr.sdist_x = 0;
	cub->g_plyr.sdist_y = 0;
	cub->g_plyr.sx = 0;
	cub->g_plyr.sy = 0;
	cub->g_plyr.movespd = 0.03;
	cub->g_plyr.rotspd = 0.02;
}

void	swne_reset(t_swne *swne)
{
	swne->s_count = 0;
	swne->w_count = 0;
	swne->n_count = 0;
	swne->e_count = 0;
}

void	fc_reset(t_fc *fc)
{
	fc->f_count = 0;
	fc->c_count = 0;
}

void	begin_reset2(t_cub *cub)
{
	swne_reset(&cub->swne);
	fc_reset(&cub->fc);
	camera_reset(cub);
	player_reset(cub);
}
