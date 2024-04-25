/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:21:57 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 16:52:57 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n > i)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
/*
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	printf("%i\n", ft_memcmp(s, sCpy, 4));
	printf("%i\n", ft_memcmp(s, s2, 0));
	printf("%i\n", ft_memcmp(s, s2, 1));
	printf("%i\n", ft_memcmp(s2, s, 1));
	printf("%i", ft_memcmp(s2, s3, 4));
	write(1, "\n", 1);
	return (0);
}*/