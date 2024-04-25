/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:22:25 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 14:59:45 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int			i;
	char		c2;
	const char	*dest;

	i = 0;
	c2 = c;
	while (src[i] != c2 && src[i])
		i++;
	if (src[i] != c2)
		return (0);
	dest = &src[i];
	return ((char *)dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s1a[] = "This is OK for now";
	int s1b = 'z';
	printf("%s\n", strchr(s1a, s1b));
	printf("%s", ft_strchr(s1a, s1b));
	return(0);
}*/