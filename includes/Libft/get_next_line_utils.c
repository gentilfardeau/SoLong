/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:34:42 by tbras             #+#    #+#             */
/*   Updated: 2024/01/10 15:34:43 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*last_node(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	checkcheck(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst && lst->content[0])
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

int	lstlen(t_list *lst)
{
	int	i;
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				count++;
				return (count);
			}
			i++;
			count++;
		}
		lst = lst->next;
	}
	return (count);
}

void	cleaning(t_list **lst)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;
	char	*str;

	if (!lst)
		return ;
	last = last_node(*lst);
	str = malloc(BUFFER_SIZE + 1);
	clean = malloc (sizeof(t_list));
	if (!clean || !str)
		return ;
	i = 0;
	j = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	i++;
	while (last->content[i - 1])
		str[j++] = last->content[i++];
	str[j] = '\0';
	clean->content = str;
	clean->next = NULL;
	freeall(lst, clean);
}

void	freeall(t_list **lst, t_list *clean)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	if (clean->content[0])
		*lst = clean;
	else
	{
		free(clean->content);
		free(clean);
	}
}
