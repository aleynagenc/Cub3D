/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_image_making.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:49 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 13:25:40 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	wall_image_make(t_cub *cub)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	cub->imgs[0].img = mlx_xpm_file_to_image(cub->mlx, \
			cub->img.ea, &x, &y);
	cub->imgs[1].img = mlx_xpm_file_to_image(cub->mlx, \
			cub->img.no, &x, &y);
	cub->imgs[2].img = mlx_xpm_file_to_image(cub->mlx, \
			cub->img.so, &x, &y);
	cub->imgs[3].img = mlx_xpm_file_to_image(cub->mlx, \
			cub->img.we, &x, &y);
	cub->imgs[0].imgadd = mlx_get_data_addr(cub->imgs[0].img, \
		&cub->bpp, &cub->line_size, &cub->endian);
	cub->imgs[1].imgadd = mlx_get_data_addr(cub->imgs[1].img, \
		&cub->bpp, &cub->line_size, &cub->endian);
	cub->imgs[2].imgadd = mlx_get_data_addr(cub->imgs[2].img, \
		&cub->bpp, &cub->line_size, &cub->endian);
	cub->imgs[3].imgadd = mlx_get_data_addr(cub->imgs[3].img, \
		&cub->bpp, &cub->line_size, &cub->endian);
}

void	mlx_image_make(t_cub *cub)
{
	cub->mlx_img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->imgaddr = mlx_get_data_addr(cub->mlx_img, &cub->bpp, \
		&cub->line_size, &cub->endian);
}

void	raycasting_column_start_end(t_cub *cub)
{
	cub->lineheight = abs((int)((double)HEIGHT / cub->g_plyr.wall_dist));
	cub->draw_start = -cub->lineheight / 2 + (double)HEIGHT / 2;
	cub->draw_end = cub->lineheight / 2 + (double)HEIGHT / 2;
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	if (cub->draw_end >= HEIGHT)
		cub->draw_end = HEIGHT - 1;
}

static void	raycasting_print_map(t_cub *cub)
{
	int	color;

	cub->y = cub->draw_start;
	while (cub->y < cub->draw_end)
	{
		cub->img.img_y = (int)((cub->y * 2 - HEIGHT + cub->lineheight)
				* (IMG_HEIGHT / 2) / cub->lineheight);
		if (cub->g_plyr.wall_dir == 0 && cub->g_plyr.dir_x > 0)
			cub->color = 0;
		else if (cub->g_plyr.wall_dir == 0 && cub->g_plyr.dir_x < 0)
			cub->color = 1;
		else if (cub->g_plyr.wall_dir == 1 && cub->g_plyr.dir_y > 0)
			cub->color = 2;
		else if (cub->g_plyr.wall_dir == 1 && cub->g_plyr.dir_y < 0)
			cub->color = 3;
		color = ((unsigned int *)cub->imgs[cub->color].imgadd) \
		[(IMG_WIDTH * cub->img.img_y + cub->img.img_x)];
		game_pixel_put(cub, cub->x, cub->y, color);
		cub->y++;
	}
}

void	raycasting_all(t_cub *cub)
{
	raycasting_init(cub);
	raycasting_player_angle(cub);
	raycasting_wall_pass(cub);
	raycasting_column_start_end(cub);
	raycasting_wall_orien(cub);
	raycasting_print_map(cub);
}
