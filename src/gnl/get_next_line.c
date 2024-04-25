/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaito <kaito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:29:44 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/04/17 20:29:33 by kaito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *stock, char *buffer)
{
	char	*temp;

	temp = ft_strjoin2(stock, buffer);
	free(stock);
	return (temp);
}

char	*ft_setline(int fd, char *stock)
{
	int		lue;
	char	*buffer;

	lue = 1;
	while (lue > 0 && ft_strchr2(stock) == 0)
	{
		buffer = malloc(BUFFER_SIZE * 1 + 1);
		lue = read(fd, buffer, BUFFER_SIZE);
		if (lue > 0 && stock == NULL)
		{
			free(buffer);
			return (NULL);
		}
		buffer[lue] = '\0';
		stock = ft_free(stock, buffer);
		free(buffer);
	}
	return (stock);
}

char	*ft_supr_before_n(char *stock)
{
	int		i;
	int		t;
	char	*temp;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] != '\0')
		i++;
	if (ft_strlen2(stock) - i == 0)
	{	
		free(stock);
		return (NULL);
	}
	temp = malloc((ft_strlen2(stock) - i) * 1 + 1);
	if (!temp)
		return (NULL);
	t = 0;
	while (stock[i])
		temp[t++] = stock[i++];
	temp[t] = '\0';
	free(stock);
	return (temp);
}

char	*ft_supr_after_n(char *stock)
{
	int		i;
	char	*temp;

	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	i++;
	temp = malloc(i * 1 + 1);
	if (!temp)
		return (NULL);
	i = 0;
	while (stock[i])
	{
		temp[i] = stock[i];
		if (stock[i] == '\n')
		{
			temp[++i] = '\0';
			return (temp);
		}
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stock)
		stock = ft_calloc2(1, 1);
	stock = ft_setline(fd, stock);
	line = ft_supr_after_n(stock);
	stock = ft_supr_before_n(stock);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int i;
// 	int fd;
// 	char *gnl;
// 	fd = open("test.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 6)
// 	{
// 		gnl = get_next_line(fd);
// 		printf("%i: %s", i, gnl);
// 		free(gnl);
// 		i++;
// 	}
// }