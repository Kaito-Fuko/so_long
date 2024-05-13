/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:36 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/13 16:32:46 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_tmp(char **maps, char **maps_tmp, int x, int y)
{
	int	i;
	int	j;

	// i = -1;
	// printf("	x = %i | y = %i\n", x, y);
	// while (maps[++i])
	// 	printf("	%s", maps[i]);
	// printf("\n\n");
	i = -1;
	maps_tmp = malloc(y * (sizeof(char *) + 1));
	if (!maps_tmp)
		return (NULL);
	while (maps[++i])
	{
		// printf("i = %i x = %i y = %i %s", i, x, y, maps[i]);
		j = -1;
		maps_tmp[i] = malloc(x * sizeof(char) + 1);
		if (!maps_tmp[i])
			return (free_split(maps_tmp), NULL);
		while (maps[i][++j])
			maps_tmp[i][j] = maps[i][j];
		maps_tmp[i][j] = '\0';
	}
	// printf("\n");
	return (maps_tmp);
}

void	init_param_zero(t_maps *maps)
{
	maps->maps = NULL;
	maps->count.c = 0;
	maps->count.e = 0;
	maps->count.p = 0;
	maps->p.x = 0;
	maps->p.y = 0;
	maps->s.x = 0;
	maps->s.y = 0;
	maps->x = 0;
	maps->y = 0;
}

int	init_maps(char *fichier, t_maps *maps)
{
	char	**maps_tmp;

	maps_tmp = NULL;
	init_param_zero(maps);
	ft_line(fichier, maps);
	ft_maps(fichier, maps);
	if (maps->maps == NULL)
		return (-1);
	ft_printf_maps(maps);
	maps_tmp = ft_tmp(maps->maps, maps_tmp, maps->x, maps->y);
	if (!maps_tmp)
		return (free_split(maps->maps), -1);
	if (check_maps(maps) == -1)
		return (free_split(maps_tmp), -1);
	if (check_chemin(maps) == -1)
		return (free_split(maps_tmp), -1);
	// ft_printf_maps(maps);
	free_split(maps->maps);
	maps->maps = ft_tmp(maps_tmp, maps->maps, maps->x, maps->y);
	// ft_printf_maps(maps); 
	free_split(maps->maps);
	return (0);
}

int	main(int ac, char **av)
{
	t_maps	*maps;

	maps = malloc(sizeof(t_maps));
	if (ac != 2)
		return (free(maps), ft_putstr_fd("Error : invalid argument\n", 2), 0);
	if (ft_check_ber(av[1]) == -1)
		return (free(maps), ft_putstr_fd("Error : invalid files\n", 2), 0);
	if (init_maps(av[1], maps) == -1)
		return (free(maps), ft_putstr_fd("Error : invalid maps\n", 2), 0);
	ft_putstr_fd("OK : valid maps\n", 1);
	
	free(maps);
	return (0);
}
