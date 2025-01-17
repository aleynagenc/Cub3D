/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_assignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:56 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 13:37:11 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	ft_exit(void *tmp)
{
	(void)tmp;
	exit(0);
}

int	button_up(int key, t_cub *cub)
{
	if (key == 13)
		cub->kbd.w = 1;
	else if (key == 1)
		cub->kbd.s = 1;
	else if (key == 0)
		cub->kbd.a = 1;
	else if (key == 2)
		cub->kbd.d = 1;
	else if (key == 123)
	{
		cub->kbd.l = 1;
		cub->g_plyr.rotspd = -0.06;
	}
	else if (key == 124)
	{
		cub->kbd.r = 1;
		cub->g_plyr.rotspd = 0.06;
	}
	else if (key == 257)
		cub->g_plyr.movespd += 0.09;
	else if (key == 53)
		exit(1);
	return (1);
}

int	button_down(int key, t_cub *cub)
{
	if (key == 13)
		cub->kbd.w = 0;
	else if (key == 1)
		cub->kbd.s = 0;
	else if (key == 0)
		cub->kbd.a = 0;
	else if (key == 2)
		cub->kbd.d = 0;
	else if (key == 123)
		cub->kbd.l = 0;
	else if (key == 124)
		cub->kbd.r = 0;
	else if (key == 257)
		cub->g_plyr.movespd -= 0.09;
	return (1);
}

void	button_assignment(t_cub *cub)
{
	mlx_hook(cub->mlx_win, 2, 0, button_up, cub);
	mlx_hook(cub->mlx_win, 3, 0, button_down, cub);
	mlx_hook(cub->mlx_win, 17, 0, ft_exit, 0);
	mlx_loop_hook(cub->mlx, print_map, cub);
}
