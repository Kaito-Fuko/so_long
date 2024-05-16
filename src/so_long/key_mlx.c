/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:25:01 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/16 17:53:13 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc(t_maps *maps)
{
	mlx_destroy_window(maps->w.m_ptr, maps->w.w_ptr);
	mlx_destroy_display(maps->w.m_ptr);
	free_split(maps->maps);
	free(maps->w.m_ptr);
	free(maps);
	exit (0);
}

int	key_esc(int keycode, t_maps *maps)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(maps->w.m_ptr, maps->w.w_ptr);
		mlx_destroy_display(maps->w.m_ptr);
		free_split(maps->maps);
		free(maps->w.m_ptr);
		free(maps);
		exit (0);
	}
	if (keycode == W)
		printf("is W\n");
	if (keycode == A)
		printf("is A\n");
	if (keycode == S)
		printf("is S\n");
	if (keycode == D)
		printf("is D\n");
	return (0);
}
