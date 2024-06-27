/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:34:27 by tbras             #+#    #+#             */
/*   Updated: 2024/01/10 15:34:28 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnlcpy(t_list *lst, char *str)
{
	int	i;
	int	j;

	if (!lst || !str)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	str[j] = '\0';
}

char	*theline(t_list *lst)
{
	int		len;
	char	*str;

	if (!lst)
		return (NULL);
	len = lstlen(lst);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	gnlcpy(lst, str);
	return (str);
}

void	lstapp(t_list **lst, char *buf)
{
	t_list	*new;
	t_list	*last;

	last = last_node(*lst);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	if (!last)
		*lst = new;
	else
		last->next = new;
	new->content = buf;
	new->next = NULL;
}

void	lstcreate(t_list **lst, int fd)
{
	char	*buf;
	int		char_read;

	while (!checkcheck(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free (buf);
			return ;
		}
		buf[char_read] = '\0';
		lstapp(lst, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
		return (NULL);
	lstcreate(&lst, fd);
	if (!lst)
		return (NULL);
	str = theline(lst);
	cleaning(&lst);
	return (str);
}
