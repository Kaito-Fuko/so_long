/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaito <kaito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:02:02 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/07 14:52:43 by kaito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_cmp(char s1, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		l;
	char	*str;

	i = 0;
	l = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1);
	while (ft_cmp(s1[i], set) == 1)
		i++;
	while (ft_cmp(s1[j - 1], set) == 1 && j != 0)
		j--;
	if (j < i)
		j = i;
	str = malloc((j - i + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < j)
		str[l++] = s1[i++];
	str[l] = '\0';
	return (str);
}
