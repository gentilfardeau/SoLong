/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:44:49 by tbras             #+#    #+#             */
/*   Updated: 2023/11/24 14:59:57 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ps;

	if (!s)
		return (NULL);
	i = 0;
	while (i < start && s[i])
		i++;
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	ps = malloc(sizeof(char) * len + 1);
	if (!ps)
		return (0);
	j = 0;
	while (s[i + j] && j < len)
	{
		ps[j] = s[i + j];
		j++;
	}
	ps[j] = '\0';
	return (ps);
}
