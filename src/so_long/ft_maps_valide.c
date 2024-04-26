/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_valide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:50:31 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/26 15:57:25 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printf_maps(t_maps *maps)
{
	int	i;

	i = -1;
	while (maps->maps[++i])
		printf("-> %s", maps->maps[i]);
	printf("\n");
	printf("pos x = %i, pos y = %i\n", maps->p.x, maps->p.y);
	printf("size x = %i, size y = %i\n", maps->s.x, maps->s.y);
	printf("\n\n");
}

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

int	check_chemin(t_maps *maps)
{
	// ft_printf_maps(maps);
	if (check_one_charac(maps->maps, maps->count) == -1)
		return (-1);
	init_param(maps, 'P');
	flood(maps->maps, maps->s, maps->p);
	// ft_printf_maps(maps);
	// printf("\n\n");
	if (check_fill(maps->maps) == -1)
		return (-1);
	// ft_printf_maps(maps);
	return (0);
}

int	ft_correct(char *maps, unsigned int size)
{
	int	i;

	i = 0;
	if (maps[i] != '1')
		return (-1);
	while (maps[i + 2] && (maps[i] == '0' || maps[i] == '1' || maps[i] == 'P'
			|| maps[i] == 'C' || maps[i] == 'E'))
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

	i = -1;
	if (!maps->maps[++i])
		return (-1);
	if (ft_check(maps->maps[i], maps->x) == -1)
		return (-1);
	// printf("ok\n");
	while (maps->maps[++i] && maps->maps[i + 1])
		if (ft_correct(maps->maps[i], maps->x) == -1)
			return (-1);
	if (maps->maps[i] && ft_check(maps->maps[i], maps->x - 1) == -1)
		return (-1);
	return (0);
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
