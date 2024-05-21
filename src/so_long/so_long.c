/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:36 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/21 18:11:46 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_maps(char *fichier, t_maps *maps)
{
	char	**maps_tmp;

	maps_tmp = NULL;
	init_param_zero(maps);
	ft_line(fichier, maps);
	ft_maps(fichier, maps);
	if (!maps->maps)
		return (-1);
	maps_tmp = ft_tmp(maps->maps, maps_tmp, maps->x, maps->y);
	if (!maps_tmp)
		return (free_split(maps->maps), -1);
	if (check_maps(maps) == -1)
		return (free_split(maps_tmp), -1);
	if (check_chemin(maps) == -1)
		return (free_split(maps_tmp), -1);
	free_split(maps->maps);
	maps->maps = ft_tmp(maps_tmp, maps->maps, maps->x, maps->y);
	free_split(maps_tmp);
	return (0);
}

void	ft_graphique(t_maps *maps)
{
	int	h;
	int	w;

	h = 50 * (maps->x - 1);
	w = 50 * maps->y;
	maps->w.m_ptr = mlx_init();
	if (!maps->w.m_ptr)
		return ;
	maps->w.w_ptr = mlx_new_window(maps->w.m_ptr, h, w, "Window");
	if (!maps->w.w_ptr)
		return ;
	ft_image(&maps->w, maps);
	image_maps(maps, maps->w.m_ptr, maps->w.w_ptr, maps->w);
	mlx_hook(maps->w.w_ptr, 17, 1l << 17, esc, maps);
	mlx_hook(maps->w.w_ptr, 2, 1L << 0, key_esc, maps);
	mlx_loop(maps->w.m_ptr);
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
	maps->count.p = 0;
	ft_graphique(maps);
	free_split(maps->maps);
	free(maps);
	return (0);
}
