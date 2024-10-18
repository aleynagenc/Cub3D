/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frgb_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:02 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:02 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	frgb_control2(char **rgbno, t_cub *cub)
{
	cub->f_rgb.red = ft_atoi(rgbno[0]);
	cub->f_rgb.green = ft_atoi(rgbno[1]);
	cub->f_rgb.blue = ft_atoi(rgbno[2]);
	if ((cub->f_rgb.red >= 0 && cub->f_rgb.red <= 255) \
		&& (cub->f_rgb.green >= 0 && cub->f_rgb.green <= 255) \
		&& (cub->f_rgb.blue >= 0 && cub->f_rgb.blue <= 255))
		cub->f_rgb.rgb = (cub->f_rgb.red << 16) | \
			(cub->f_rgb.green << 8) | cub->f_rgb.blue;
	else
	{
		printf("Frgb code range is incorrect!\nError\n");
		exit(1);
	}
}

void	frgb_control(char *Frgb, t_cub *cub)
{
	char	**rgbno;

	while (*Frgb == ' ' || *Frgb == '\t')
		Frgb++;
	rgbno = ft_split2(Frgb + 1, ',', cub);
	while (rgbno[cub->frgb_i])
	{
		cub->frgb_j = 0;
		while (rgbno[cub->frgb_i][cub->frgb_j])
		{
			if (rgbno[cub->frgb_i][cub->frgb_j] != ' ' && \
				rgbno[cub->frgb_i][cub->frgb_j] != '\t' && \
				!ft_is_digit(rgbno[cub->frgb_i][cub->frgb_j]))
			{
				printf("The color code is incorrect!\nError\n");
				exit(1);
			}
			cub->frgb_j++;
		}
		cub->frgb_i++;
	}
	number_control(cub->frgb_i);
	frgb_control2(rgbno, cub);
	free_fcno(rgbno);
}
