/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_space_player_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:41 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 13:06:24 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	error_message(void)
{
	printf("Map is not close!\nError\n");
	exit(1);
}

void	skip_line(int e, int i, int t, char **m)
{
	int	j;

	while (m[i])
	{
		t = j;
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == '0')
			{
				if ((m[i][j - 1] == ' ' || m[i][j - 1] == '\0' || \
					m[i][j + 1] == ' ') || \
					(t > j && m[i - 1][j] == ' ') || (t < j || !m[i - 1][j]))
					error_message();
				if ((e > i || !m[i + 1][j]) && (m[i + 1][j] == ' ' || \
					!m[i + 1][j]))
					error_message();
			}
			j++;
		}
		i++;
	}
}

void	skip_line2(int e, int i, int t, char **m)
{
	int	j;

	while (m[i])
	{
		t = j;
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'W' || m[i][j] == 'S' || m[i][j] == 'N' || \
				m[i][j] == 'E')
			{
				if ((m[i][j - 1] == ' ' || m[i][j - 1] == '\0' || \
					m[i][j + 1] == ' ') || \
					(t > j && m[i - 1][j] == ' ') || (t < j || !m[i - 1][j]))
					error_message();
				if ((e > i || !m[i + 1][j]) && (m[i + 1][j] == ' ' || \
					!m[i + 1][j]))
					error_message();
			}
			j++;
		}
		i++;
	}
}

void	map_zero_control(t_cub *cub)
{
	int		i;
	int		end;
	int		temp;
	char	**map;

	temp = 0;
	i = 0;
	end = 0;
	map = cub->map;
	while (map[i])
		i++;
	end = i - 1;
	i = 6;
	skip_line(end, i, temp, map);
	skip_line2(end, i, temp, map);
}
