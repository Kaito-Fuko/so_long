/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:20:23 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/15 14:25:42 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	i;

	i = ft_lstsize(lst);
	while (i > 0)
	{
		f(lst->content);
		lst = lst->next;
		i--;
	}
	lst = NULL;
}
