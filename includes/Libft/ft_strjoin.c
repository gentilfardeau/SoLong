/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:45:29 by tbras             #+#    #+#             */
/*   Updated: 2023/11/29 18:26:45 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*ps;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	ps = malloc (sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ps)
		return (NULL);
	while (s1[i])
	{
		ps[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ps[i + j] = s2[j];
		j++;
	}
	ps[i + j] = '\0';
	return (ps);
}
