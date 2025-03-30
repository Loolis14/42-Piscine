/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:51:06 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/15 08:43:11 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	n1;
	int	n2;
	int	sum;

	if (index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		return (0);
	}
	n1 = 0;
	n2 = 1;
	sum = 1;
	while (index - 1 > 0)
	{
		sum = n1 + n2;
		n1 = n2;
		n2 = sum;
		--index;
		ft_fibonacci(index);
	}
	return (sum);
}
