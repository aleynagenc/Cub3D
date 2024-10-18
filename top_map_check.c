/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_map_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:43 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:43 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	image_trans_two(char *chr, t_cub *cub)
{
	int		fd;

	while (*chr == ' ' || *chr == '\t')
		chr++;
	fd = open(chr + 3, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strcmp(chr, "NO"))
			cub->img.no = ft_strdup(chr + 3);
		else if (ft_strcmp(chr, "SO"))
			cub->img.so = ft_strdup(chr + 3);
		else if (ft_strcmp(chr, "WE"))
			cub->img.we = ft_strdup(chr + 3);
		else if (ft_strcmp(chr, "EA"))
			cub->img.ea = ft_strdup(chr + 3);
		close(fd);
	}
	else if (fd == -1)
	{
		printf("Picture is not true\nError\n");
		close(fd);
		exit(1);
	}
}

void	image_trans_one(char *chr, t_cub *cub)
{
	int		fd;

	while (*chr == ' ' || *chr == '\t')
		chr++;
	fd = open(chr + 2, O_RDONLY);
	if (fd != -1)
	{
		if (ft_strcmpc(chr, 'N'))
			cub->img.no = ft_strdup(chr + 2);
		else if (ft_strcmpc(chr, 'S'))
			cub->img.so = ft_strdup(chr + 2);
		else if (ft_strcmpc(chr, 'W'))
			cub->img.we = ft_strdup(chr + 2);
		else if (ft_strcmpc(chr, 'E'))
			cub->img.ea = ft_strdup(chr + 2);
		close(fd);
	}
	else if (fd == -1)
	{
		printf("Picture is not true\nError\n");
		close(fd);
		exit(1);
	}
}

void	image_trans(char *map, t_cub *cub)
{
	if (ft_strcmp(map, "NO") || ft_strcmp(map, "SO") \
		|| ft_strcmp(map, "WE") || ft_strcmp(map, "EA"))
		image_trans_two(map, cub);
	else if (ft_strcmpc(map, 'N') || ft_strcmpc(map, 'S') \
		|| ft_strcmpc(map, 'W') || ft_strcmpc(map, 'E'))
		image_trans_one(map, cub);
	else
	{
		printf("Map Arguman is wrong\nError\n");
		exit(1);
	}
}

void	top_map_check(t_cub *cub, int i)
{
	if (ft_strcmp(cub->map[i], "NO") || ft_strcmpc(cub->map[i], 'N') \
		|| ft_strcmp(cub->map[i], "SO") || ft_strcmpc(cub->map[i], 'S') \
		|| ft_strcmp(cub->map[i], "WE") || ft_strcmpc(cub->map[i], 'W') \
		|| ft_strcmp(cub->map[i], "EA") || ft_strcmpc(cub->map[i], 'E'))
		image_trans(cub->map[i], cub);
	else if (ft_strcmpc(cub->map[i], 'F'))
		frgb_control(cub->map[i], cub);
	else if (ft_strcmpc(cub->map[i], 'C'))
		crgb_control(cub->map[i], cub);
}
