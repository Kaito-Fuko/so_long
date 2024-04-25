/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:22:02 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 14:59:50 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (src[size])
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char s[10] = "";
	printf("before : %s\n", s);
	printf("after strdup : %s\n", strdup(s));
	printf("after ft_strdup : %s\n", ft_strdup(s));
}*/