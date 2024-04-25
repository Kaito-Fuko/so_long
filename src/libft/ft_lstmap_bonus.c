/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:27:30 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/16 12:42:36 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;

	if (!lst || !del)
		return (0);
	nlst = malloc(sizeof(t_list));
	if (!nlst)
		return (0);
	while (lst)
	{
		nlst->content = f(lst);
		if (nlst->content)
		{
			ft_lstclear(&nlst, del);
			free(lst);
			return (0);
		}
		nlst = nlst->next;
		lst = lst->next;
	}
	nlst->next = NULL;
	return (nlst);
}
