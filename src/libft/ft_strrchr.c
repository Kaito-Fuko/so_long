/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:07 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 15:00:57 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int			i;
	int			j;
	char		c2;
	const char	*dest;

	i = 0;
	j = 0;
	c2 = c;
	while (src[i])
	{
		if (src[i] == c2)
			j = i;
		i++;
	}
	dest = &src[j];
	if (c2 == 0)
		return ((char *)&src[i]);
	if (src[j] != c2)
		return (0);
	return ((char *)dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1a[] = "This is OK for now";
	int s1b = 'z';
	printf("%s\n", strrchr(s1a, s1b));
	//printf("%s", ft_strrchr(s1a, s1b));
	return(0);
}*/