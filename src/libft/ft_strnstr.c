/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:48:56 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 15:59:15 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	i;
	int		j;

	if (size == 0 && str == 0)
		return (NULL);
	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i] && i <= size)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && str[i + j] && (i + j) < size)
			{
				j++;
				if (to_find[j] == '\0')
					return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
{
	int	i;
	int	j;
	int	str_len;

	str_len = ft_strlen(to_find);
	if (str_len == 0)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && str[i + j])
			{
				j++;
				if (to_find[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>
int main()
{
	char *s = "hello";
	char *c = "l";
	printf("%s\n", strstr(s,c));
	printf("%s", ft_strnstr(s,c,5));
	return (0);
}*/