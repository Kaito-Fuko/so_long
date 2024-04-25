/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:43:10 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/15 13:13:42 by jhatchi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nlist;

	if (!lst)
		return ;
	nlist = ft_lstlast(*lst);
	if (!nlist)
		*lst = new;
	else
		nlist->next = new;
}
/*
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
#include <string.h>

int main()
{
	t_list *l = ft_lstnew(strdup("nyacat"));
    t_list *n = ft_lstnew(strdup("OK"));

    ft_lstadd_back(&l, n);
}
*/