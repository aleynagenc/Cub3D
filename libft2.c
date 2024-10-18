/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:13 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:14 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

char	*ft_strchr(const char *str, int c)
{
	while (str && *str && *str != c)
		str++;
	if (c && !*str)
		return (NULL);
	return ((char *)str);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
	{
		str[n] = (unsigned char )c;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (!str)
		return (0);
	return (ft_memset(str, '\0', count * size));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == ' ' || s1[i] == '\t')
		i++;
	if (s1[i] == s2[0])
	{
		if (s1[i + 1] == s2[1] && s1[i + 1] != ' ')
			return (1);
		else
			return (0);
	}
	return (0);
}
