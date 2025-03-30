/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:24:34 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/13 12:49:30 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	size_t	i;

	i = 0;
	while (n > 0 && s1[i])
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		else if (n == 1 && (s1[i] == s2[i]))
		{
			--n;
		}
		else
		{
			++i;
			--n;
		}
	}
	return (s1[i] - s2[i]);
}

int	ft_len(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		++len;
	}
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	size_t	i;
	size_t	len_t_f;

	len_t_f = ft_len(to_find);
	if (!*to_find)
	{
		return (str);
	}
	i = 0;
	while (str[i])
	{
		if (ft_strncmp((str + i), to_find, len_t_f) == 0)
		{
			return (str + i);
		}
		++i;
	}
	return (NULL);
}
