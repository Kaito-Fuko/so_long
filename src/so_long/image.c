/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:04 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/17 12:57:43 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_win *win)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	win->m = mlx_xpm_file_to_image(win->m_ptr, "src/image/v.xpm", &w, &h);
	win->f = mlx_xpm_file_to_image(win->m_ptr, "src/image/b.xpm", &w, &h);
	win->p = mlx_xpm_file_to_image(win->m_ptr, "src/image/a.xpm", &w, &h);
	win->c = mlx_xpm_file_to_image(win->m_ptr, "src/image/a.xpm", &w, &h);
	win->e = mlx_xpm_file_to_image(win->m_ptr, "src/image/a.xpm", &w, &h);
}

void	image_maps(char **maps, void *m_ptr, void *w_ptr, t_win w)
{
	int	i;
	int	j;

	i = -1;
	while (maps[++i])
	{
		j = -1;
		while (maps[i][++j])
		{
			if (maps[i][j] == '0')
				mlx_put_image_to_window(m_ptr, w_ptr, w.f, (j * 50), (i * 50));
			if (maps[i][j] == '1')
				mlx_put_image_to_window(m_ptr, w_ptr, w.m, (j * 50), (i * 50));
			if (maps[i][j] == 'P')
				mlx_put_image_to_window(m_ptr, w_ptr, w.p, (j * 50), (i * 50));
			if (maps[i][j] == 'C')
				mlx_put_image_to_window(m_ptr, w_ptr, w.c, (j * 50), (i * 50));
			if (maps[i][j] == 'E')
				mlx_put_image_to_window(m_ptr, w_ptr, w.e, (j * 50), (i * 50));
		}
	}
}
