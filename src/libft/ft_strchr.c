/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaito <kaito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:22:25 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/07 14:51:55 by kaito            ###   ########.fr       */
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
