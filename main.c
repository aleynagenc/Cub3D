/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:26 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 13:33:36 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static int	start_game(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "Cub3D");
	wall_image_make(cub);
	mlx_image_make(cub);
	button_assignment(cub);
	mlx_loop(cub->mlx);
	return (0);
}

int	main(int ac, char *av[])
{
	t_cub	cub;

	if (ac != 2)
	{
		printf("Invalid number of arguments!\nError\n");
		exit(1);
	}
	else
	{
		begin_reset(&cub);
		map_control(av, &cub);
		if (!start_game(&cub))
		{
			printf("Game is not start\nError\n");
			exit(1);
		}
	}
	return (0);
}
