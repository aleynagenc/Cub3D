/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:04 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 13:35:43 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	game_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*offset;

	offset = cub->imgaddr + (y * (cub->line_size) + x * \
		(cub->bpp / 8));
	*(unsigned int *) offset = color;
}

void	f_rgb_down_color(t_cub *cub)
{
	while (cub->y < HEIGHT)
	{
		game_pixel_put(cub, cub->x, HEIGHT - cub->y - 1, cub->c_rgb.rgb);
		cub->y++;
	}
}

void	c_rgb_up_color(t_cub *cub)
{
	if (cub->draw_end < 0)
		cub->draw_end = HEIGHT;
	cub->y = cub->draw_end;
	while (cub->y < HEIGHT)
	{
		game_pixel_put(cub, cub->x, cub->y, cub->f_rgb.rgb);
		cub->y++;
	}
}

int	print_map(t_cub *cub)
{
	if (cub->kbd.w || cub->kbd.s || cub->kbd.a || cub->kbd.d \
		|| cub->kbd.l || cub->kbd.r || cub->t_cam.display)
	{
		cub->t_cam.display = 0;
		cub->x = 0;
		cub->y = 0;
		key_move(cub, &cub->t_cam);
		while (cub->x < WIDTH)
		{
			raycasting_all(cub);
			f_rgb_down_color(cub);
			c_rgb_up_color(cub);
			cub->x++;
		}
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
	return (1);
}
