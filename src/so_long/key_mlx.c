/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:25:01 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/22 13:24:10 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_correct(t_maps *maps, int *p, int x, int y)
{
	if (maps->maps[p[0] + x][p[1] + y] == 'E' && maps->count.c == maps->count.p)
		esc(maps);
	if (maps->maps[p[0] + x][p[1] + y] == 'C')
		maps->count.p += 1;
	maps->maps[p[0]][p[1]] = '0';
	maps->maps[p[0] + x][p[1] + y] = 'P';
	p[0] = p[0] + x;
	p[1] = p[1] + y;
	maps->count.e += 1;
}

int	key_esc(int keycode, t_maps *maps)
{
	if (keycode == ESC)
		esc(maps);
	ft_found_e(maps->maps, maps);
	if (keycode == W)
		ft_is_w(maps, maps->w);
	if (keycode == A)
		ft_is_a(maps, maps->w);
	if (keycode == S)
		ft_is_s(maps, maps->w);
	if (keycode == D)
		ft_is_d(maps, maps->w);
	return (0);
}

void	ft_found_e(char **maps, t_maps *ma_ps)
{
	int	i;
	int	j;

	i = -1;
	while (maps[++i])
	{
		j = -1;
		while (maps[i][++j])
		{
			if (maps[i][j] == 'E')
			{
				ma_ps->s.x = i;
				ma_ps->s.y = j;
				return ;
			}
		}
	}
}

int	esc(t_maps *maps)
{
	if (maps->count.c == maps->count.p)
		ft_putstr_fd("GAGNER !!\n", 1);
	ft_putstr_fd("Vous avez fait ", 1);
	ft_putnbr_fd(maps->count.e, 1);
	ft_putstr_fd(" de coup, pour recupere ", 1);
	ft_putnbr_fd(maps->count.p, 1);
	ft_putstr_fd(" d'oeuf.\n", 1);
	if (maps->w.m)
		mlx_destroy_image(maps->w.m_ptr, maps->w.m);
	if (maps->w.f)
		mlx_destroy_image(maps->w.m_ptr, maps->w.f);
	if (maps->w.p)
		mlx_destroy_image(maps->w.m_ptr, maps->w.p);
	if (maps->w.c)
		mlx_destroy_image(maps->w.m_ptr, maps->w.c);
	if (maps->w.e)
		mlx_destroy_image(maps->w.m_ptr, maps->w.e);
	if (maps->w.ex)
		mlx_destroy_image(maps->w.m_ptr, maps->w.ex);
	mlx_destroy_window(maps->w.m_ptr, maps->w.w_ptr);
	mlx_destroy_display(maps->w.m_ptr);
	free_split(maps->maps);
	free(maps->w.m_ptr);
	free(maps);
	exit (0);
}
