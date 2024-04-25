/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:22:16 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 15:46:07 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_print(int i, int b, int n, char *str)
{
	if (n == 0 || n < 0)
	{
		if (n == 0)
			str[0] = '0';
		else
			str[0] = '-';
		n = -n;
		i++;
		b++;
	}
	if (n == -2147483648)
	{
		str[0] = '-';
		str[b++] = '2';
		n = 147483648;
	}
	str[i--] = '\0';
	while (i >= b)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		b;
	char	*str;

	i = ft_intlen(n);
	b = 0;
	if (n == 0)
		str = (char *) malloc(2 * sizeof(char));
	else if (n < 0)
		str = (char *) malloc((i + 2) * sizeof(char));
	else
		str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_print(i, b, n, str);
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char *i1 = ft_itoa(-1234);
}
*/