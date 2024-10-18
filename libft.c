/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:54:12 by agenc             #+#    #+#             */
/*   Updated: 2024/01/18 11:54:13 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy (dest, s1, len + 1);
	dest[len + 1] = '\0';
	return (dest);
}

static int	check_alp(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (-1);
		else if (str[i] == ' ')
			i++;
		else if ((str[i] >= 'a' && str[i] <= 'z') \
			|| (str[i] >= 'A' && str[i] <= 'Z'))
			return (-1);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	a;
	int	c;

	a = 0;
	c = 0;
	while (str[a] == '\t' || str[a] == ' ' || str[a] == '\n'
		|| str[a] == '\v' || str[a] == '\f' || str[a] == '\r')
		a++;
	if (str[a] == '\0')
		return (-1);
	while (str[a] >= '0' && str[a] <= '9')
	{
		c = (c * 10) + (str[a] - '0');
		a++;
	}
	if (check_alp(str + a) == -1)
		return (-1);
	return (c);
}

int	ft_strcmpc(const char *s1, const char s2)
{
	while (*s1 == ' ' || *s1 == '\t')
		s1++;
	if (*s1 == s2)
		return (1);
	return (0);
}
