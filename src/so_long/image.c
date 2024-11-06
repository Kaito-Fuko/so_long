/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:04 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/07/02 15:24:42 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_win *win, t_maps *maps)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	win->m = mlx_xpm_file_to_image(win->m_ptr, "src/image/m.xpm", &w, &h);
	if (!win->m)
		esc(maps);
	win->f = mlx_xpm_file_to_image(win->m_ptr, "src/image/s.xpm", &w, &h);
	if (!win->f)
		esc(maps);
	win->p = mlx_xpm_file_to_image(win->m_ptr, "src/image/p.xpm", &w, &h);
	if (!win->p)
		esc(maps);
	win->c = mlx_xpm_file_to_image(win->m_ptr, "src/image/c1.xpm", &w, &h);
	if (!win->c)
		esc(maps);
	win->e = mlx_xpm_file_to_image(win->m_ptr, "src/image/1e.xpm", &w, &h);
	if (!win->e)
		esc(maps);
	win->ex = mlx_xpm_file_to_image(win->m_ptr, "src/image/2e.xpm", &w, &h);
	if (!win->ex)
		esc(maps);
}

void	image_maps(t_maps *maps, void *m_ptr, void *w_ptr, t_win w)
{
	int	l;
	int	i;
	int	j;

	l = 50;
	i = -1;
	while (maps->maps[++i])
	{
		j = -1;
		while (maps->maps[i][++j])
		{
			if (maps->maps[i][j] == '0' || maps->maps[i][j] == 'P')
				mlx_put_image_to_window(m_ptr, w_ptr, w.f, (j * l), (i * l));
			if (maps->maps[i][j] == '1')
				mlx_put_image_to_window(m_ptr, w_ptr, w.m, (j * l), (i * l));
			if (maps->maps[i][j] == 'P')
				mlx_put_image_to_window(m_ptr, w_ptr, w.p, (j * l), (i * l));
			if (maps->maps[i][j] == 'C')
				mlx_put_image_to_window(m_ptr, w_ptr, w.c, (j * l), (i * l));
			if (maps->maps[i][j] == 'E' && maps->count.c != maps->count.p)
				mlx_put_image_to_window(m_ptr, w_ptr, w.e, (j * l), (i * l));
			if (maps->maps[i][j] == 'E' && maps->count.c == maps->count.p)
				mlx_put_image_to_window(m_ptr, w_ptr, w.ex, (j * l), (i * l));
		}
	}
}
