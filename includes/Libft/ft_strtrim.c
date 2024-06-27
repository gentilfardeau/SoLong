/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:46:43 by tbras             #+#    #+#             */
/*   Updated: 2023/11/24 18:41:36 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// A FIX : Ya une connerie avec les \t ou les \n mais on va chercher trop loin 

size_t	ft_detect(char const c, char const *set)
{
	size_t	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}	
	return (0);
}

size_t	ft_customcpy(char *ps, char const *s, size_t min, size_t max)
{
	size_t	i;
	size_t	j;

	i = min;
	j = 0;
	while (s[j] && i + j < max)
	{
		ps[j] = s[i + j];
		j++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ps;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (ft_detect(s1[i], set) == 1)
		i++;
	while (ft_detect(s1[j - 1], set) == 1)
		j--;
	if (j == 0)
	{
		ps = malloc(1);
		ps[0] = '\0';
		return (ps);
	}
	ps = malloc(sizeof(char) * (j - i) + 1);
	if (!ps)
		return (NULL);
	k = ft_customcpy(ps, s1, i, j);
	ps[k] = '\0';
	return (ps);
}
