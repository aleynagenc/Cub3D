/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:28 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 13:10:56 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	error_file(void)
{
	printf("Incorrect file extension!\nError\n");
	exit(1);
}

void	error_comma(t_cub *cub)
{
	if (cub->comma != 2)
	{
		printf("Wrong number of commas!\nError\n");
		exit(1);
	}
	cub->comma = 0;
}

void	comma_counter(char map, t_cub *cub)
{
	if (map == ',')
		cub->comma++;
}

int	av_check(char *str)
{
	int	length;

	length = ft_strlen(str);
	if (length >= 5 && \
		str[length - 1] == 'b' && \
		str[length - 2] == 'u' && \
		str[length - 3] == 'c' && \
		str[length - 4] == '.')
		return (1);
	else
		return (0);
}

void	swne_fc_control(char *map, t_cub *cub)
{
	if (cub->swne.s_count != 1 || cub->swne.w_count != 1 || \
		cub->swne.n_count != 1 || cub->swne.e_count != 1)
	{
		printf("Check out S, W, N and E!\nError\n");
		free(map);
		exit(1);
	}
	if (cub->fc.f_count != 1 || cub->fc.c_count != 1)
	{
		printf("Check out F and C!\nError\n");
		free(map);
		exit(1);
	}
}
