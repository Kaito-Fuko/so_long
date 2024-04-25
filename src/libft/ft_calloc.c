/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:33:34 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 18:44:10 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	if (size == 0 || nmemb == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	else if (size > 65535 || nmemb > 65535 || nmemb * size > 65535)
		return (NULL);
	else
		str = malloc(nmemb * size);
	if (!str)
		return (0);
	while (size * nmemb > i)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
/*
int	main()
{
        void * d1 = ft_calloc(30, 1);
        void * d2 = calloc(30, 1);
}*/