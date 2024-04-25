/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:57:49 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/16 15:02:30 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	str_len;

	if (size == 0 && dest == NULL)
		return (0);
	str_len = ft_strlen(dest);
	if (size < str_len)
		return (size + ft_strlen(src));
	i = 0;
	while ((i + str_len + 1) < size && src[i])
	{
		dest[str_len + i] = src[i];
		i++;
	}
	dest[str_len + i] = '\0';
	return (str_len + ft_strlen(src));
}
/*
int	main()
{
	char d[10] = "origami";
	char s[10] = "master";
	printf("%d", ft_strlcat(d, s, 9));
	return(0);
}*/