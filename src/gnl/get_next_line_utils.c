/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaito <kaito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:08:42 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/17 20:29:57 by kaito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr2(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\n' && src[i])
		i++;
	if (src[i] != '\n')
		return (0);
	return (2);
}

void	*ft_calloc2(unsigned long long int nmemb, unsigned long long int size)
{
	unsigned long long int		i;
	char						*str;

	i = 0;
	if (size == 0 || nmemb == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
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

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc((ft_strlen2(s1) + ft_strlen2(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
