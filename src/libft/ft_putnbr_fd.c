/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:28:47 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/14 14:56:19 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	a;
	int	b;

	a = n % 10;
	b = n / 10;
	if (b)
		ft_putnbr_fd(b, fd);
	if (n < 0)
	{
		if (!b)
			ft_putchar_fd('-', fd);
		a = -a;
	}
	ft_putchar_fd((a + '0'), fd);
}
