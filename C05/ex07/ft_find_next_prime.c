/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:52:34 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/18 13:01:02 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	unsigned int	i;

	if (nb == 3 || nb == 2)
	{
		return (1);
	}
	if (nb % 2 == 0 || nb % 3 == 0 || nb < 2)
	{
		return (0);
	}
	i = 5;
	while ((i * i) <= (unsigned int)nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
		{
			return (0);
		}
		i = i + 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
	{
		return (2);
	}
	while (!(ft_is_prime(nb)))
	{
		++nb;
	}
	return (nb);
}
