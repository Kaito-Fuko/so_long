/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:48:37 by kaito             #+#    #+#             */
/*   Updated: 2024/04/25 17:59:12 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_size
{
	int	x;
	int y;
}	t_size;

typedef struct s_pos
{
	int	x;
	int y;
}	t_pos;

typedef struct s_maps
{
	unsigned int	x;
	unsigned int	y;
	char			**maps;
	t_pos			p;
	t_size			s;
	struct s_maps	*next;
}	t_maps;

typedef struct s_tlist
{
	t_maps			*maps;
	struct s_tlist	*next;
}	t_tlist;

// so_long
int		init_maps(char *fichier, t_maps *maps);

// init_maps
int		ft_check_ber(char *str);
void	ft_line(char *fichier, t_maps *maps);
void	ft_maps(char *fichier, t_maps *maps);

// ft_maps_valide
int		ft_check(char *maps, unsigned int size);
int		ft_correct(char *maps, unsigned int size);
int		check_maps(t_maps *maps);
int		check_chemin(char **maps_tmp, t_maps *maps);

#endif