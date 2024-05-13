/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaito <kaito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:30:24 by jhatchi-          #+#    #+#             */
/*   Updated: 2024/05/07 14:51:10 by kaito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tlst;
	t_list	*nlst;

	if (!lst || !del)
		return ;
	nlst = *lst;
	while (nlst)
	{
		tlst = nlst->next;
		ft_lstdelone(nlst, del);
		nlst = tlst;
	}
	*lst = NULL;
}
