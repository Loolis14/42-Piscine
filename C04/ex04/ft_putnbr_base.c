/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:51:36 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/27 13:14:20 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

int	check_base(char *base)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_len(base);
	if (size < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= 20)
			return (0);
		++i;
	}
	i = 1;
	while (base[i])
	{
		if (base[i] == base[i - 1])
			return (0);
		++i;
	}
	return (1);
}

void	ft_recursive(unsigned int n, char *base, size_t size)
{
	char	c;
	
	if (n >= size)
		ft_recursive((n / size), base, size);
	c = base[n % size];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	size_t			size;

	if (!check_base(base))
		return ;
	size = ft_len(base);
	n = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	ft_recursive(n, base, size);
}
