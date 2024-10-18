/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:33 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 13:10:12 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	swne_control(char *map, t_cub *cub, int *i)
{
	if (map[*i] == 'S' || map[*i] == 'W' || \
	map[*i] == 'N' || map[*i] == 'E')
	{
		if (map[*i] == 'S' || (map[*i] == 'S' && map[(*i) + 1] == 'O'))
			cub->swne.s_count++;
		else if (map[*i] == 'W' || (map[*i] == 'W' && map[(*i) + 1] == 'E'))
			cub->swne.w_count++;
		else if (map[*i] == 'N' || (map[*i] == 'N' && map[(*i) + 1] == 'O'))
			cub->swne.n_count++;
		else if (map[*i] == 'E' || (map[*i] == 'E' && map[(*i) + 1] == 'A'))
			cub->swne.e_count++;
		while (map[*i] != '.')
			(*i)++;
		if (map[*i] == '.' && map[*i - 1] == ' ')
		{
			if (map[*i + 1] == '/')
				(*i)++;
			else
				error_file();
		}
		else
			error_file();
		while (map[*i] && map[*i] != '\n')
			(*i)++;
	}
}

void	first_space_error(void)
{
	printf("There are invalid characters in the .cub file!\nError\n");
	exit(1);
}

int	first_space_wall(char map, t_cub *cub, int *index)
{
	if (map == '1')
	{
		cub->map_start_index = *index;
		return (0);
	}
	return (1);
}

int	space_tab_control(char *map, int *index)
{
	if (map[*index] == ' ' || map[*index] == '\t' || map[*index] == '\n')
	{
		while (map[*index] == ' ' || map[*index] == '\t' || map[*index] == '\n')
			(*index)++;
		return (0);
	}
	return (1);
}

void	fc_control(char *map, t_cub *cub, int *index)
{
	if (map[*index] == 'F' )
		cub->fc.f_count++;
	else if (map[*index] == 'C')
		cub->fc.c_count++;
	(*index)++;
}
