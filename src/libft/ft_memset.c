/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:52:56 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/15 17:41:06 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s1, int c, size_t n)
{
	int		i;
	char	c2;
	char	*s2;

	i = 0;
	c2 = c;
	s2 = (char *)s1;
	while (n > 0)
	{
		s2[i++] = c2;
		n--;
	}
	return (s1);
}
/*
int main()
{
        const int size = 18;
        char b1[0xF00];
        char *r2 = ft_memset(b1, 'A', size);
        r2 = ft_memset("", 'A', 0);
}*/