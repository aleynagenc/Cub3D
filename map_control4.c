/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:32 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 12:48:50 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static int	first_space(char *map, t_cub *cub)
{
	int	index;

	index = 0;
	while (map[index])
	{
		if (map[index] == 'F' || map[index] == 'C')
		{
			fc_control(map, cub, &index);
			while (map[index] && map[index] != '\n')
			{
				comma_counter(map[index], cub);
				index++;
			}
			error_comma(cub);
		}
		swne_control(map, cub, &index);
		if (!first_space_wall(map[index], cub, &index))
			break ;
		else if (!space_tab_control(map, &index))
			continue ;
		else
			first_space_error();
	}
	swne_fc_control(map, cub);
	return (index);
}

static int	end_space(char *map)
{
	int	index;

	index = 0;
	while (map[index])
		index++;
	index--;
	while (map[index])
	{
		if (map[index] == '1')
			break ;
		if (map[index] != ' ' && map[index] != '\t' && map[index] != '\n')
		{
			printf("There are invalid characters in the .cub file!\nError\n");
			exit(1);
		}
		index--;
	}
	return (index);
}

void	error_mes(void)
{
	printf("The map is divided!\nError\n");
	exit(1);
}

static void	wall_check(char *map, int j)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] && i < j - 1)
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			error_mes();
		else if (map[i] == '\n')
		{
			if (count == 0)
				error_mes();
			count = 0;
			i++;
		}
		else if (map[i] == '1')
		{
			count++;
			i++;
		}
		else
			i++;
	}
}

void	map_valid_check(char *map, t_cub *cub)
{
	int	first;
	int	end;
	int	index;

	first = first_space(map, cub);
	end = end_space(map);
	index = end - first;
	wall_check(map + first, index);
	map_char_control(map + first);
	map_out_control(map + first);
}
