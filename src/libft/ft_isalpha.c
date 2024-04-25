/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:18:59 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 14:58:08 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	printf("%i\n", ft_isalpha('a' - 1));
	printf("%i\n", ft_isalpha('a'));
	printf("%i\n", ft_isalpha('z' + 1));
	printf("%i\n", ft_isalpha('z'));
	printf("%i\n", ft_isalpha('A' - 1));
	printf("%i\n", ft_isalpha('A'));
	printf("%i\n", ft_isalpha('Z' + 1));
	printf("%i\n", ft_isalpha('Z'));
	write(1, "\n", 1);
	return (0);
}*/