/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhatchi- <jhatchi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:30:24 by jhatchi-          #+#    #+#             */
/*   Updated: 2023/11/15 14:19:05 by jhatchi-         ###   ########.fr       */
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
/*
void	ft_bzero(void *s, int n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		s++;
		n--;
	}
}

void	lstdel_f(void *s)
{
	s += 1;
}

int	main()
{
    char *content = "hello !";
	t_list	*list;

    list = malloc(sizeof(t_list));
    ft_bzero(list, sizeof(t_list));
    list->next = malloc(sizeof(t_list));
    ft_bzero(list->next, sizeof(t_list));
    list->content = content;
    list->next->content = content + 2;
    ft_lstclear(&list, lstdel_f);
    write(2, "", 1);
}*/