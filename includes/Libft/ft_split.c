/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbras <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:05:24 by tbras             #+#    #+#             */
/*   Updated: 2023/11/29 19:05:25 by tbras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_checkcheck(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	check;

	i = 0;
	j = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] != c && check == 0)
		{
			j++;
			check = 1;
		}
		if (s[i] == c)
			check = 0;
	i++;
	}
	return (j);
}

char	*ft_splitcpy(char const *s, size_t min, size_t max)
{
	size_t	i;
	char	*ps;

	i = 0;
	ps = malloc (sizeof(char) * (max - min + 1));
	if (!ps)
		return (0);
	while (min < max)
	{
		ps[i] = s[min];
		i++;
		min++;
	}
	ps[i] = '\0';
	return (ps);
}

void	ft_clearall(size_t	nb, char **pps)
{
	while (pps[nb] && nb > 0)
	{
		free(pps[nb]);
		nb--;
	}
	free(pps);
}

size_t	ft_cpycpy(char const *s, char c, char **pps)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			pps[j] = ft_splitcpy(s, start, i);
			if (!pps[j])
			{
				ft_clearall (j, pps);
				return (-1);
			}
			j++;
			start = -1;
		}	
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**pps;

	if (!s)
		return (0);
	pps = malloc(sizeof(char *) * (ft_checkcheck(s, c) + 1));
	if (!pps)
		return (0);
	j = ft_cpycpy(s, c, pps);
	if (j == -1)
		return (0);
	pps[j] = 0;
	return (pps);
}
