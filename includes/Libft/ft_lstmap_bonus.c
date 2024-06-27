/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:19:18 by tbras             #+#    #+#             */
/*   Updated: 2023/12/12 16:19:19 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*fnode;
	t_list	*newlist;

	if (!lst || !f || !del)
		return (NULL);
	newlist = 0;
	while (lst)
	{
		fnode = ft_lstnew(f(lst -> content));
		if (!fnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, fnode);
		lst = lst -> next;
	}
	return (newlist);
}
