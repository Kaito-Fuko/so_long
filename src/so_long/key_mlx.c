/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:25:01 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/21 18:10:50 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc(t_maps *maps)
{
	if (maps->w.c)
		mlx_destroy_image(maps->w.m_ptr, maps->w.c);
	if (maps->w.m)
		mlx_destroy_image(maps->w.m_ptr, maps->w.m);
	if (maps->w.f)
		mlx_destroy_image(maps->w.m_ptr, maps->w.f);
	if (maps->w.p)
		mlx_destroy_image(maps->w.m_ptr, maps->w.p);
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
}

void	ft_is_w(t_maps *maps, t_win w)
{
	int p[2];
	int	i;
	int	j;

	p[0] = maps->pe;
	p[1] = maps->per;
	if (maps->maps[p[0] + -1][p[1] + 0] == '1')
		return ;
	check_correct(maps, p, -1, 0);
	maps->pe = p[0];
	maps->per = p[1];
	j = maps->s.x;
	i = maps->s.y;
	if (maps->maps[maps->s.x][maps->s.y] == '0')
		maps->maps[maps->s.x][maps->s.y] = 'E';
	image_maps(maps, w.m_ptr, w.w_ptr, w);
}

void	ft_is_a(t_maps *maps, t_win w)
{
	int p[2];
	int	i;
	int	j;

	p[0] = maps->pe;
	p[1] = maps->per;
	if (maps->maps[p[0] + 0][p[1] + -1] == '1')
		return ;
	check_correct(maps, p, 0, -1);
	maps->pe = p[0];
	maps->per = p[1];
	j = maps->s.x;
	i = maps->s.y;
	if (maps->maps[maps->s.x][maps->s.y] == '0')
		maps->maps[maps->s.x][maps->s.y] = 'E';
	image_maps(maps, w.m_ptr, w.w_ptr, w);
}

void	ft_is_s(t_maps *maps, t_win w)
{
	int p[2];
	int	i;
	int	j;

	p[0] = maps->pe;
	p[1] = maps->per;
	if (maps->maps[p[0] + 1][p[1] + 0] == '1')
		return ;
	check_correct(maps, p, 1, 0);
	maps->pe = p[0];
	maps->per = p[1];
	j = maps->s.x;
	i = maps->s.y;
	if (maps->maps[maps->s.x][maps->s.y] == '0')
		maps->maps[maps->s.x][maps->s.y] = 'E';
	image_maps(maps, w.m_ptr, w.w_ptr, w);
}

void	ft_is_d(t_maps *maps, t_win w)
{
	int p[2];
	int	i;
	int	j;

	p[0] = maps->pe;
	p[1] = maps->per;
	if (maps->maps[p[0] + 0][p[1] + 1] == '1')
		return ;
	check_correct(maps, p, 0, 1);
	maps->pe = p[0];
	maps->per = p[1];
	j = maps->s.x;
	i = maps->s.y;
	if (maps->maps[maps->s.x][maps->s.y] == '0')
		maps->maps[maps->s.x][maps->s.y] = 'E';
	image_maps(maps, w.m_ptr, w.w_ptr, w);
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
