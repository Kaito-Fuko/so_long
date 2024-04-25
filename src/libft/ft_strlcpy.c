/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:22:38 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/13 15:31:12 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = ft_strlen(src);
	if (i + 1 < size)
	{
		while (j < i + 1)
		{
			dest[j] = src[j];
			j++;
		}
	}
	else if (size > 0)
	{
		while (j < size - 1)
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}
/*
int main()
{
	char s[10] = "origami";
	char c[10] = "maste";
	printf("%s", ft_strlcpy(s, c, 6));
	return (0);
}*/