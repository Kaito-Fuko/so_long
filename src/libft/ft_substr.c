/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:50:30 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/22 15:08:28 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = malloc(1 + len * sizeof(char));
	if (!str)
		return (0);
	j = 0;
	i = start;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char * s = ft_substr("0123456789", 9, 10);
	printf("before : %s\n", s);
	printf("after ft_substr : %s\n", s);
}*/