/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crgb_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:58 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:53:58 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	free_fcno(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}

void	crgb_control2(char **rgbno, t_cub *cub)
{
	cub->c_rgb.red = ft_atoi(rgbno[0]);
	cub->c_rgb.green = ft_atoi(rgbno[1]);
	cub->c_rgb.blue = ft_atoi(rgbno[2]);
	if ((cub->c_rgb.red >= 0 && cub->c_rgb.red <= 255) \
		&& (cub->c_rgb.green >= 0 && cub->c_rgb.green <= 255) \
		&& (cub->c_rgb.blue >= 0 && cub->c_rgb.blue <= 255))
		cub->c_rgb.rgb = (cub->c_rgb.red << 16) | \
			(cub->c_rgb.green << 8) | cub->c_rgb.blue;
	else
	{
		printf("Crgb code range is incorrect!\nError\n");
		exit(1);
	}
}

void	number_control(int i)
{
	if (i != 3)
	{
		printf("F or C argument counts is fail!\nError\n");
		exit(1);
	}
}

void	crgb_control(char *Crgb, t_cub *cub)
{
	char	**cgbno;

	while (*Crgb == ' ' || *Crgb == '\t')
		Crgb++;
	cgbno = ft_split2(Crgb + 1, ',', cub);
	while (cgbno[cub->crgb_i])
	{
		cub->crgb_j = 0;
		while (cgbno[cub->crgb_i][cub->crgb_j])
		{
			if (cgbno[cub->crgb_i][cub->crgb_j] != ' ' && \
				cgbno[cub->crgb_i][cub->crgb_j] != '\t' && \
				!ft_is_digit(cgbno[cub->crgb_i][cub->crgb_j]))
			{
				printf("The color code is incorrect!\nError\n");
				exit(1);
			}
			cub->crgb_j++;
		}
		cub->crgb_i++;
	}
	number_control(cub->crgb_i);
	crgb_control2(cgbno, cub);
	free_fcno(cgbno);
}
