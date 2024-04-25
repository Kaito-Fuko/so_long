/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_valide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:50:31 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/25 18:13:44 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(char *maps, unsigned int size)
{
	int	i;

	i = -1;
	while (maps[++i])
		if (maps[i] != '1')
			break ;
	if (ft_strlen(maps) == size && maps[i + 1] == '\0')
		return (0);
	return (-1);
}

int	ft_correct(char *maps, unsigned int size)
{
	int	i;

	i = 0;
	if (maps[i] != '1')
		return (-1);
	while (maps[i + 2])
		i++;
	if (maps[i] != '1')
		return (-1);
	if (ft_strlen(maps) == size)
		return (0);
	return (-1);
}

int	check_maps(t_maps *maps)
{
	int	i;

	i = 0;
	if (!maps->maps[i])
		return (-1);
	if (ft_check(maps->maps[i], maps->x) == -1)
		return (-1);
	printf("ok\n");
	while (maps->maps[i] && maps->maps[i + 1])
	{
		if (ft_correct(maps->maps[i], maps->x) == -1)
			return (-1);
		i++;
	}
	if (maps->maps[i] && ft_check(maps->maps[i], maps->x - 1) == -1)
		return (-1);
	return (0);
}

void	ft_printf_maps(t_maps *maps)
{
	int i;

	i = -1;
	while (maps->maps[++i])
		printf("%s", maps->maps[i]);
	printf("\n");
	printf("pos x = %i, pos y = %i\n", maps->p.x, maps->p.y);
	printf("size x = %i, size y = %i\n", maps->s.x, maps->s.y);
	printf("\n\n");
}

void	prem_charac(t_maps *maps, char c)
{
	maps->p.y = 0;
	while (maps->maps[maps->p.y])
	{
		maps->p.x = 0;
		while (maps->maps[maps->p.y][maps->p.x] != '\0')
		{
			if (maps->maps[maps->p.y][maps->p.x] == c)
				break ;
			maps->p.x++;
		}
		if (maps->maps[maps->p.y][maps->p.x] == c)
			break ;
		maps->p.y++;
	}
}

void	init_param(t_maps *maps, char c)
{
	maps->s.y = maps->y;
	maps->s.x = ft_strlen(maps->maps[0]);
	prem_charac(maps, c);
}

void	flood(char **tab, t_size size, t_pos cur)
{
	// printf("cur x = %i, cur y = %i charac = %c\nsize x = %i size y = %i\n", cur.x, cur.y, tab[cur.y][cur.x], size.x, size.y);
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

int	check_chemin(char **maps_tmp, t_maps *maps)
{
	ft_printf_maps(maps);
	init_param(maps, 'P');
	flood(maps_tmp, maps->s, maps->p);
	int i = -1;
	while (maps_tmp[++i])
		printf("| %s", maps_tmp[i]);
	printf("\n\n");
	if (check_fill(maps_tmp) == -1)
		return (-1);
	ft_printf_maps(maps);
	return (0);
}
