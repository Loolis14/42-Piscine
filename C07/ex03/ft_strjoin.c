/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:25:32 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/19 15:48:55 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char **s, int size, char *sep)
{
	int	len;
	int	len_s;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (s[i][j])
		{
			++len;
			++j;
		}
		++i;
	}
	i = 0;
	len_s = 0;
	while (*(sep + i))
	{
		++len_s;
		++i;
	}
	return (len + (len_s * (size - 1)));
}

char	*ft_stpcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*p;
	char	*end_p;
	int		i;

	if (size <= 0)
	{
		p = malloc(1);
		if (p == NULL)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	p = malloc(ft_len(strs, size, sep) + 1);
	if (p == NULL)
		return (0);
	i = 0;
	end_p = p;
	while (i < size)
	{
		end_p = ft_stpcpy(end_p, strs[i]);
		if (i != size - 1)
			end_p = ft_stpcpy(end_p, sep);
		i++;
	}
	return (p);
}
