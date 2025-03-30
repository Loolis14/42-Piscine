/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:32:43 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/24 10:32:29 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_len(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_dup(char *s)
{
	int		i;
	char	*d;

	d = malloc(ft_len(s) + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		++i;
	}
	d[i] = '\0';
	return (d);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*p;
	int					i;

	p = malloc((ac + 1) * (sizeof(t_stock_str)));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (NULL);
		p[i].size = ft_len(av[i]);
		p[i].str = av[i];
		p[i].copy = ft_dup(av[i]);
		++i;
	}
	p[i].str = NULL;
	return (p);
}
