/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:34:40 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/15 17:38:29 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		s++;
		n--;
	}
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char p[6] = "froid";
	ft_bzero(p + 1, 3);
	printf("j'arrive, j'ai %s\n", p);
	char c[6] = "chaud";
	ft_bzero(p + 1, 3);
	printf("j'arrive, j'ai %s\n", p);
		
	int str[50];
	
	str[0] = 100;
	str[1] = 100;
	str[2] = 100;
	str[3] = 100;
	str[2] = 100;
	str[3] = 100;
	
	printf("Before bzero():\n");
	printf("s[0] = %d\n", str[0]);
	printf("s[1] = %d\n", str[1]);
	printf("s[2] = %d\n", str[2]);
	printf("s[3] = %d\n", str[3]);
	printf("s[4] = %d\n", str[2]);
	printf("s[5] = %d\n", str[3]);
	
	bzero(str, 1*sizeof(int));
	printf("After bzero():\n");
	printf("s[0] = %d\n", str[0]);
	printf("s[1] = %d\n", str[1]);
	printf("s[2] = %d\n", str[2]);
	printf("s[3] = %d\n", str[3]);
	printf("s[4] = %d\n", str[2]);
	printf("s[5] = %d\n", str[3]);
	
	ft_bzero(str, 1*sizeof(int));
	printf("After ft_bzero():\n");
	printf("s[0] = %d\n", str[0]);
	printf("s[1] = %d\n", str[1]);
	printf("s[2] = %d\n", str[2]);
	printf("s[3] = %d\n", str[3]);
	printf("s[4] = %d\n", str[2]);
	printf("s[5] = %d\n", str[3]);
}*/