/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:48:37 by kaito             #+#    #+#             */
/*   Updated: 2024/05/22 13:20:22 by jhatchi-         ###   ########.fr       */
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
# include <mlx.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

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

typedef struct s_win
{
	void	*m_ptr;
	void	*w_ptr;
	void	*m;
	void	*f;
	void	*p;
	void	*c;
	void	*e;
	void	*ex;
}	t_win;

typedef struct s_maps
{
	unsigned int	x;
	unsigned int	y;
	int				pe;
	int				per;
	char			**maps;
	t_count			count;
	t_pos			p;
	t_size			s;
	t_win			w;
}	t_maps;

// so_long
void	ft_graphique(t_maps *maps);
int		init_maps(char *fichier, t_maps *maps);

// init_maps
void	free_split(char **str);
void	init_param_zero(t_maps *maps);
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
void	init_param(t_maps *maps, char c);
void	flood(char **tab, t_size size, t_pos cur);
int		check_fill(char **maps);
char	**ft_tmp(char **maps, char **maps_tmp, int x, int y);
int		check_one_charac(char **maps, t_count count, t_maps *ma_ps);

// key_mlx
void	check_correct(t_maps *maps, int *p, int x, int y);
int		key_esc(int keycode, t_maps *maps);
void	ft_found_e(char **maps, t_maps *ma_ps);
int		esc(t_maps *maps);

// image
void	ft_image(t_win *win, t_maps *maps);
void	image_maps(t_maps *maps, void *m_ptr, void *w_ptr, t_win win);

// is_key
void	ft_is_w(t_maps *maps, t_win w);
void	ft_is_a(t_maps *maps, t_win w);
void	ft_is_s(t_maps *maps, t_win w);
void	ft_is_d(t_maps *maps, t_win w);

#endif
