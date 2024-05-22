/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:17:27 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/22 13:18:06 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_w(t_maps *maps, t_win w)
{
	int	p[2];
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
	int	p[2];
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
	int	p[2];
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
	int	p[2];
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
