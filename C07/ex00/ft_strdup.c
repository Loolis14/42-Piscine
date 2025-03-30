/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:09:18 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/17 10:17:31 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_len(char *src)
{
	size_t	len;

	len = 0;
	while (src[len])
	{
		++len;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*p;
	size_t	len_s;
	size_t	i;

	len_s = ft_len(src);
	p = malloc(len_s + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
