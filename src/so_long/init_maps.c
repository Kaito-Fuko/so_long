/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:52:13 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/22 12:26:06 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	init_param_zero(t_maps *maps)
{
	maps->maps = NULL;
	maps->count.c = 0;
	maps->count.e = 0;
	maps->count.p = 0;
	maps->w.ex = NULL;
	maps->w.m = NULL;
	maps->w.f = NULL;
	maps->w.p = NULL;
	maps->w.c = NULL;
	maps->w.e = NULL;
	maps->p.x = 0;
	maps->p.y = 0;
	maps->s.x = 0;
	maps->s.y = 0;
	maps->per = 0;
	maps->pe = 0;
	maps->x = 0;
	maps->y = 0;
}

int	ft_check_ber(char *str)
{
	size_t	i;
	int		j;
	char	*ber;

	ber = ".ber";
	i = ft_strlen(str) - 1;
	j = ft_strlen(ber) - 1;
	while (ber[j] && ber[j] == str[i] && str[i] && i > 0 && j > 0)
	{
		j--;
		i--;
	}
	if (open(str, O_RDONLY) > 0)
		if (j == 0)
			return (i);
	return (-1);
}

void	ft_line(char *fichier, t_maps *maps)
{
	int		fd;
	char	*ligne;

	fd = open(fichier, O_RDONLY);
	if (fd < 0)
		return ;
	ligne = get_next_line(fd);
	if (ligne == NULL)
		return ;
	maps->x = ft_strlen(ligne);
	maps->y = 1;
	while (ligne != NULL && ft_strlen(ligne) == maps->x)
	{
		free(ligne);
		ligne = get_next_line(fd);
		maps->y++;
	}
	free(ligne);
}

void	ft_maps(char *fichier, t_maps *maps)
{
	int				fd;
	unsigned int	i;

	i = -1;
	fd = open(fichier, O_RDONLY);
	if (fd < 0)
		return ;
	if (maps->y == 0 && maps->x == 0)
		return ;
	maps->maps = malloc((maps->y + 1) * (sizeof(char *)));
	if (!maps->maps)
		return ;
	while (++i < maps->y && maps->x != 0)
	{
		maps->maps[i] = get_next_line(fd);
		if (!maps->maps[i])
			return (free_split(maps->maps));
		maps->maps[i][ft_strlen(maps->maps[i])] = '\0';
	}
	maps->maps[maps->y] = NULL;
}
