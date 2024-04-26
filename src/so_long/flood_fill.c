/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:57:10 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/26 16:00:27 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood(char **tab, t_size size, t_pos cur)
{
	// printf("cur x = %i, cur y = %i charac = %c\nsize x = %i 
	// size y = %i\n", cur.x, cur.y, tab[cur.y][cur.x], size.x, size.y);
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
		{
			// printf("%c", maps[i][j]);
			if (maps[i][j] == 'C' || maps[i][j] == 'P' || maps[i][j] == 'E')
				return (-1);
		}
	}
	return (0);
}

int	check_one_charac(char **maps, t_count count)
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
				count.p++;
			if (maps[i][j] == 'E')
				count.e++;
			if (maps[i][j] == 'C')
				count.c++;
		}
	}
	if (count.c > 0 && count.e == 1 && count.p == 1)
		return (count.p);
	return (-1);
}
