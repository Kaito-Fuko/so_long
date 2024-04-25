/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:36 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/25 18:12:44 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_maps(char *fichier, t_maps *maps)
{
	char **maps_tmp;
	
	ft_line(fichier, maps);
	ft_maps(fichier, maps);
	if (check_maps(maps) == -1)
		return (-1);
	maps_tmp = maps->maps;
	if (check_chemin(maps_tmp, maps) == -1)
		return (-1);
	printf("ok\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_maps	*maps;
	t_tlist	**data;

	(void)av;
	data = NULL;
	maps = malloc(sizeof(t_maps));
	if (ac != 2)
		return (ft_putstr_fd("Error : invalid argument\n", 2), 0);
	if (ft_check_ber(av[1]) == -1)
		return (ft_putstr_fd("Error : invalid files\n", 2), 0);
	if (init_maps(av[1], maps) == -1)
		return (ft_putstr_fd("Error : invalid maps\n", 2), 0);
	return (0);
}
