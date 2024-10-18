/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:29 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:58:51 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	read_map2(t_cub *cub, char *av, int fd)
{
	char	*map_line;

	map_line = get_map(fd, av);
	cub->map = ft_split(map_line, '\n', cub);
	map_valid_check(map_line, cub);
	map_zero_control(cub);
	free(map_line);
}

void	read_map(t_cub *cub, char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		printf("The file could not be read!\nError\n");
		exit(1);
	}
	read_map2(cub, av, fd);
}

int	map_len(char *av)
{
	int		char_count;
	char	c;
	int		fd;

	char_count = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open file!\nError\n");
		exit(1);
	}
	while (read(fd, &c, 1) > 0)
		char_count++;
	close(fd);
	if (char_count == 0)
	{
		printf("File is empty!\nError\n");
		exit(1);
	}
	return (char_count);
}

char	*get_map(int fd, char *av)
{
	int		bufsize;
	ssize_t	bytes_read;
	char	*map;

	bufsize = map_len(av);
	map = (char *)ft_calloc(bufsize + 1, sizeof(char));
	if (map == NULL)
		return (NULL);
	bytes_read = read(fd, map, bufsize);
	if (bytes_read == -1 || bytes_read == 0)
	{
		free(map);
		exit(1);
	}
	map[bytes_read] = '\0';
	return (map);
}

void	map_control(char **av, t_cub *cub)
{
	if (!av_check(av[1]))
	{
		printf("Incorrect file extension!\nError\n");
		exit(0);
	}
	read_map(cub, av[1]);
	trans_image_rgb(cub);
	gmap_int(cub);
}
