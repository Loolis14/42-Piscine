/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:30:09 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/09 10:30:19 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	condition(int x, int y, int x0, int y0)
{
	if (y0 == 0 || y0 == y - 1)
	{
		while (x0 <= x - 1)
		{
			if (x0 == 0)
				ft_putchar('A');
			else if (x0 == x - 1)
				ft_putchar('C');
			else
				ft_putchar('B');
			x0++;
		}
	}
	else
	{
		while (x0 <= x - 1)
		{
			if (x0 == 0 || x0 == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			x0++;
		}
	}
}

void	rush00(int x, int y)
{
	int	x0;
	int	y0;

	if (x == 0)
	{
		ft_putchar('\n');
		return ;
	}
	y0 = 0;
	while (y0 <= y - 1)
	{
		x0 = 0;
		condition(x, y, x0, y0);
		y0++;
		ft_putchar('\n');
	}
}
