/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:41:02 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/23 16:04:02 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	diff;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && ((unsigned char)s1[i] && (unsigned char)s2[i])
		&& ((unsigned char)s1[i] == (unsigned char)s2[i]))
		i++;
	diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}
