/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:02:16 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/17 16:31:28 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	unsigned int	sum;

	if (power < 0)
	{
		return (0);
	}
	sum = 1;
	while (power >= 1)
	{
		sum = sum * nb;
		--power;
	}
}
