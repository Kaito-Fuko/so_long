/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:48:37 by kaito             #+#    #+#             */
/*   Updated: 2024/04/26 16:04:43 by jhatchi-         ###   ########.fr       */
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
	int	y;
}	t_size;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_count
{
	int	p;
	int	c;
	int	e;
}	t_count;

typedef struct s_maps
{
	unsigned int	x;
	unsigned int	y;
	char			**maps;
	t_count			count;
	t_pos			p;
	t_size			s;
	struct s_maps	*next;
}	t_maps;

// so_long
void	init_param_zero(t_maps *maps);
char	**ft_tmp(char **maps, char **maps_tmp, int x, int y);
int		init_maps(char *fichier, t_maps *maps);

// init_maps
void	init_param(t_maps *maps, char c);
void	free_split(char **str);
int		ft_check_ber(char *str);
void	ft_line(char *fichier, t_maps *maps);
void	ft_maps(char *fichier, t_maps *maps);

// ft_maps_valide
int		ft_check(char *maps, unsigned int size);
int		check_chemin(t_maps *maps);
int		ft_correct(char *maps, unsigned int size);
int		check_maps(t_maps *maps);
void	prem_charac(t_maps *maps, char c);

// flood_fill
void	flood(char **tab, t_size size, t_pos cur);
int		check_fill(char **maps);
int		check_one_charac(char **maps, t_count count);

// a supr
void	ft_printf_maps(t_maps *maps);	//in ft_maps_valide.c

#endif