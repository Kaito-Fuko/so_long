/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:57:10 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/21 16:18:03 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_param(t_maps *maps, char c)
{
	maps->s.y = maps->y;
	maps->s.x = ft_strlen(maps->maps[0]);
	prem_charac(maps, c);
}

void	flood(char **tab, t_size size, t_pos cur)
{
	if ((cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
			|| tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'A'))
		return ;
	tab[cur.y][cur.x] = 'A';
	flood(tab, size, (t_pos){cur.x - 1, cur.y});
	flood(tab, size, (t_pos){cur.x + 1, cur.y});
	flood(tab, size, (t_pos){cur.x, cur.y - 1});
	flood(tab, size, (t_pos){cur.x, cur.y + 1});
}

int	check_fill(char **maps)
{
	int	i;
	int	j;

	i = -1;
	while (maps[++i])
	{
		j = -1;
		while (maps[i][++j])
			if (maps[i][j] == 'C' || maps[i][j] == 'P' || maps[i][j] == 'E')
				return (-1);
	}
	return (0);
}

char	**ft_tmp(char **maps, char **maps_tmp, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	maps_tmp = malloc((y + 1) * (sizeof(char *)));
	if (!maps_tmp)
		return (NULL);
	while (maps[++i])
	{
		j = -1;
		maps_tmp[i] = malloc(x * sizeof(char) + 1);
		if (!maps_tmp[i])
			return (free_split(maps_tmp), NULL);
		while (maps[i][++j])
			maps_tmp[i][j] = maps[i][j];
		maps_tmp[i][j] = '\0';
	}
	maps_tmp[i] = NULL;
	return (maps_tmp);
}

int	check_one_charac(char **maps, t_count count, t_maps *ma_ps)
{
	int	i;
	int	j;

	i = -1;
	while (maps[++i])
	{
		j = -1;
		while (maps[i][++j])
		{
			if (maps[i][j] == 'P')
			{
				count.p++;
				ma_ps->pe = i;
				ma_ps->per = j;
			}
			if (maps[i][j] == 'E')
				count.e++;
			if (maps[i][j] == 'C')
				ma_ps->count.c++;
		}
	}
	if (ma_ps->count.c > 0 && count.e == 1 && count.p == 1)
		return (count.p);
	return (-1);
}
