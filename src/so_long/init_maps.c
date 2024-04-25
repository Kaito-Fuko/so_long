/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:52:13 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/25 18:08:01 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	maps->y = 0;
	while (ligne != NULL && ft_strlen(ligne) == maps->x)
	{
		free(ligne);
		ligne = get_next_line(fd);
		maps->y++;
	}
}

void	ft_maps(char *fichier, t_maps *maps)
{
	int				fd;
	unsigned int	i;

	i = -1;
	fd = open(fichier, O_RDONLY);
	if (fd < 0)
		return ;
	maps->maps = (char **)malloc(maps->x * sizeof(char *) + 1);
	while (++i <= maps->y)
	{
		maps->maps[i] = malloc(maps->x * sizeof(char) + 1);
		if (!maps->maps[i])
			return ;
		maps->maps[i] = get_next_line(fd);
	}
	maps->maps[i] = NULL;
}
