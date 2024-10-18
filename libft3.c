/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:22 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:23 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static	size_t	word_count(char const *str, char chr)
{
	size_t	cnt;

	cnt = 0;
	while (str[cnt] != '\0' && str[cnt] != chr)
		cnt++;
	if (str[cnt] == 0)
		cnt--;
	return (cnt);
}

static	size_t	len_word(char const *s, char c, t_cub *cub)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == '\n')
			cub->new_cnt++;
		len++;
	}
	len = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c, t_cub *cub)
{
	char	**res;
	size_t	index;
	size_t	two_index;
	size_t	word_len;

	word_len = len_word(s, c, cub);
	cub->row_cnt = word_len;
	res = (char **)ft_calloc(word_len + 1, sizeof(char *));
	if (res == 0)
		return (0);
	index = -1;
	while (++index < word_len)
	{
		while (*s == c && *s != '\0')
			s++;
		res[index] = (char *)ft_calloc(word_count(s, c) + 2, sizeof(char));
		two_index = 0;
		while (*s != c && *s != '\0')
			res[index][two_index++] = *s++;
		res[index][two_index] = 0;
	}
	cub->row_len = two_index;
	res[index] = 0;
	return (res);
}

char	**ft_split2(char const *s, char c, t_cub *cub)
{
	size_t	two_index;

	cub->row_cnt = len_word(s, c, cub);
	cub->res = (char **)ft_calloc(cub->row_cnt + 1, sizeof(char *));
	if (cub->res == 0)
		return (0);
	cub->res_i = -1;
	while (++cub->res_i < cub->row_cnt)
	{
		while (*s == c && *s != '\0')
			s++;
		cub->res[cub->res_i] = ft_calloc(word_count(s, c) + 2, sizeof(char));
		two_index = 0;
		while (*s != c && *s != '\0')
		{
			while (*s == ' ' || *s == '\t')
				s++;
			if (*s != c)
				cub->res[cub->res_i][two_index++] = *s++;
		}
		cub->res[cub->res_i][two_index] = 0;
	}
	cub->row_len = two_index;
	cub->res[cub->res_i] = 0;
	return (cub->res);
}
