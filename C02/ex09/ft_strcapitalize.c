/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:42:09 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/11 09:46:19 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_lowercase(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}

char	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char	ft_isalphanum(char c)
{
	return (ft_isalpha(c) || (c >= 48 && c <= 57));
}

char	*ft_strcapitalize(char *str)
{
	size_t	i;

	ft_lowercase(str);
	i = 0;
	if (ft_isalpha(str[0]))
	{
		str[0] -= 32;
	}
	i = 1;
	while (str[i])
	{
		if (ft_isalpha(str[i]) && !ft_isalphanum(str[i - 1]))
		{
			str[i] -= 32;
		}
		++i;
	}
	return (str);
}
