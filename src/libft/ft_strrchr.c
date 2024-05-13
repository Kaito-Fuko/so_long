/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaito <kaito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:07 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/07 14:52:37 by kaito            ###   ########.fr       */
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
