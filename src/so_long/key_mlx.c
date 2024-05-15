/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:25:01 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/15 17:09:36 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_esc(int keycode, t_maps *maps)
{
	printf("%i\n", keycode);
	if (keycode == 65307)
	{
		// free_split(maps->maps);
		// free(maps);
		mlx_destroy_window(maps->w.m_ptr, maps->w.w_ptr);
		exit (0);
	}
	return (0);
}
