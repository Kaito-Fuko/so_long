/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaito <kaito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:53:52 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/07 14:51:46 by kaito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_strword(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
	{
		i++;
	}
	return (i);
}

static int	ft_countword(const char *s, char c)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	if (s[0] != c && s[0] != 0)
	count++;
	while (s[j])
	{
		if ((s[j] == c && s[j + 1] != c) && s[j + 1] != 0)
			count++;
		j++;
	}
	return (count);
}

static char	**ft_print(const char *s, char **str, char c)
{
	int	i;
	int	j;
	int	pa;

	i = 0;
	pa = 0;
	while (s[pa])
	{
		j = 0;
		while (s[pa] == c)
		pa++;
		while (s[pa] != c && s[pa])
		{
			str[i][j++] = s[pa++];
			str[i][j] = '\0';
		}
		i++;
	}
	str[ft_countword(s, c)] = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		l;
	char	**str;

	l = 0;
	if (!s)
		return (0);
	str = (char **) malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			str[l++] = malloc((ft_strword(&s[i], c) + 1) * sizeof(char));
			if (!str)
				return (0);
			i += ft_strword(&s[i], c);
		}
		else
			i++;
	}
	ft_print(s, str, c);
	return ((char **)str);
}
