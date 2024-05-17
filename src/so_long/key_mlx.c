/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:25:01 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/17 13:32:34 by jhatchi-         ###   ########.fr       */
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

int	check_correct(t_maps *maps, int *p, int x, int y)
{
	if (maps->maps[p[0]][p[1]] == '1')
		return (-1);
	if (maps->maps[p[0]][p[1]] == 'C')
		maps->maps[p[0] + x][p[1] + y] = 'P';
	if (maps->maps[p[0]][p[1]] == '0')
		maps->maps[p[0] + x][p[1] + y] = 'P';
	return (0);
}

void	ft_is_w(t_maps *maps)
{
	int	*p;

	p = ft_found_p(maps->maps);
	if (p[0] == -1 || check_correct(maps, p, 0, -1) == -1)
		return ;
	image_maps(maps->maps, maps->w.m_ptr, maps->w.w_ptr, maps->w);
}

void	ft_is_a(t_maps *maps)
{
	int	*p;

	p = ft_found_p(maps->maps);
	if (check_correct(maps, p, 0, 1) == -1)
		return ;
	image_maps(maps->maps, maps->w.m_ptr, maps->w.w_ptr, maps->w);
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
		ft_is_w(maps);
	if (keycode == A)
		ft_is_a(maps);
	// if (keycode == S)
	// 	ft_is_s(maps);
	// if (keycode == D)
	// 	ft_is_d(maps);
	return (0);
}

int *ft_found_p(char **maps)
{
	int	i;
	int	j;
	int *p;

	i = -1;
	p = NULL;
	while (maps[++i])
	{
		j = -1;
		while (maps[i][++j])
		{
			if (maps[i][j] == 'P')
			{
				p[0] = i;
				p[1] = j;
				return (p);
			}
		}
	}
	return (p);
}
