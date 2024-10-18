/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:23 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 12:50:58 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	map_char_control(char *map)
{
	int	i;
	int	count_swne;
	int	count_other;

	i = 0;
	count_swne = 0;
	count_other = 0;
	while (map[i])
	{
		if (map[i] == 'E' || map[i] == 'W' || map[i] == 'S' || map[i] == 'N')
			count_swne++;
		else if (map[i] != '0' && map[i] != '1' && map[i] != ' ' && \
			map[i] != '\n' && map[i] != '\t')
			count_other++;
		i++;
	}
	if (count_swne != 1 || count_other > 0)
	{
		printf("Invalid map!\nError\n");
		exit(1);
	}
}

void	end_line(char *map, int *i)
{
	*i -= 2;
	while (map[*i] == '1')
		(*i)--;
	if (map[*i] == '0')
		error_message();
}

void	short_map_control(char *map, int *i)
{
	while (map[*i] && (map[*i] == ' ' || map[*i] == '\t'))
		(*i)++;
	while (map[*i] && map[*i] == '1')
		(*i)++;
	while ((map[*i] && map[*i] != '\n'))
		(*i)++;
}

void	first_line_control(char *map, int *i)
{
	while (map[*i] && (map[*i] == '1' || map[*i] == ' ' || map[*i] == '\t'))
		(*i)++;
	if (map[*i] != '\n')
		error_message();
	(*i)++;
}

void	map_out_control(char *map)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	first_line_control(map, &i);
	while (map[i])
	{
		short_map_control(map, &i);
		tmp = i;
		if (map[tmp] == '\n' && map[tmp + 1] == '\n')
			break ;
		if (map[tmp] == '\n')
		{
			tmp--;
			while (map[tmp] == ' ' || map[tmp] == ' ')
				tmp--;
		}
		if (map[tmp] == '\n')
			break ;
		if (map[tmp] != '1')
			error_message();
		i++;
	}
	end_line(map, &i);
}
