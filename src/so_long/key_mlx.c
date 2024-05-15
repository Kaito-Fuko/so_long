/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:25:01 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/15 17:28:42 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_esc(int keycode, t_maps *maps)
{
	printf("%i\n", keycode);
	if (keycode == 65307)
	{
		free_split(maps->maps);
		mlx_destroy_window(maps->w.m_ptr, maps->w.w_ptr);
		mlx_destroy_display(maps->w.m_ptr);
		free(maps->w.m_ptr);
		free(maps);
		exit (0);
	}
	return (0);
}
