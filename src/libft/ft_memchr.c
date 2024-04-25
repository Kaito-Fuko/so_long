/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:19:14 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/15 17:39:21 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c2;

	c2 = c;
	while (n > 0)
	{
		if (c2 == *(unsigned char *)s)
			return ((unsigned char *)s);
		s++;
		n--;
	}
	return (0);
}
