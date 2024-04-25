/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:01:36 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/15 17:43:58 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	char		*s;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char d[100] = "origami";
	char s[100] = "origqmim";
	printf("before : %s %s\n", d, s);
	printf("after memmove : %p\n", memmove(d, s, 3));
	printf("after ft_memmove : %p\n", ft_memmove(d, s, 3));
}*/