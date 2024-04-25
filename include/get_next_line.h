/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaito <kaito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:27:33 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/17 20:56:54 by kaito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_cmp(char *ligne);
char	*ft_stock(char *buffer);
size_t	ft_strlen2(const char *str);
int		ft_strchr2(const char *src);
void	*ft_calloc2(unsigned long long int nmemb, unsigned long long int size);
char	*ft_strjoin2(char const *s1, char const *s2);

#endif