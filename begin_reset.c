/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:51 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:53:52 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	key_reset(t_kbd *key)
{
	key->a = 0;
	key->d = 0;
	key->s = 0;
	key->w = 0;
	key->l = 0;
	key->r = 0;
}

void	rgb_reset(t_rgb *rgb)
{
	rgb->blue = 0;
	rgb->green = 0;
	rgb->red = 0;
	rgb->rgb = 0;
}

void	cub_reset(t_cub *cub)
{
	cub->map_start_index = 0;
	cub->row_cnt = 0;
	cub->row_len = 0;
	cub->counter = 0;
	cub->arg_c = 0;
	cub->arg_i = 0;
	cub->arg_count = 0;
	cub->c_count = 0;
	cub->i_count = 0;
	cub->crgb_j = 0;
	cub->crgb_i = 0;
	cub->frgb_i = 0;
	cub->frgb_j = 0;
	cub->res_i = 0;
	cub->comma = 0;
}

void	begin_reset(t_cub *cub)
{
	rgb_reset(&cub->f_rgb);
	rgb_reset(&cub->c_rgb);
	key_reset(&cub->kbd);
	cub_reset(cub);
	begin_reset2(cub);
}
