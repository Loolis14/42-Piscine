/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_recursives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:53:58 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/23 21:54:16 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int ft_len(const char *s)
{
    int len;

    len = 0;
    while (s[len])
    {
        ++len;
    }
    return (len);
}

void    print_under_99(const char *s_nb)
{
	int len_nb;
	const char	*number;
	size_t	n;

    len_nb = ft_len(s_nb);
	if (len_nb == 2 && s_nb[0] != '1')
	{
		n = s_nb[0] - '0';
		number = get_dizaine(n);
		write(1, get_dizaine(n), ft_len(number));
		if (s_nb[1] == '0')
		{
			++s_nb;
		}
		else
		{
			write(1, " ",1);
			print_under_99(s_nb + 1);
		}
	}
	else if (len_nb == 2 && s_nb[0] == '1')
	{
		n = ((s_nb[0] - '0') * 10 + (s_nb[1] - '0'));
		print_special_case(n);
		s_nb += 2;
	}
	else
	{
		n = s_nb[0] - '0';
		print_special_case(n);
		++s_nb;
	}
}

void	print_over_100(const char *s_nb)
{
	size_t  len_nb;
	const char *number;
	size_t  x;
	size_t  n;

	len_nb = ft_len(s_nb);
	if (len_nb % 3 == 0)
	{
		n = s_nb[0] - '0';
		print_special_case(n);
		write(1, " ", 1);
		write(1, "hundred", 7);
		++s_nb;
	}
	x = (s_nb[0] - '0') * 10 + (s_nb[1] - '0');
	if (s_nb[0] == '0' && s_nb[1] == '0')
	{
		s_nb += 2;
	}
	else if (s_nb[0] == '0' && s_nb[1] != '0')
	{
		++s_nb;
		write(1, " and ", 5);
		n = s_nb[0] - '0';
		print_special_case(n);
		++s_nb;
	}
	else if (x <= 19)
	{
		write(1, " and ", 5);
		n = ((s_nb[0] - '0') * 10 + (s_nb[1] - '0'));
		print_special_case(n);
		s_nb += 2;
	}
	else
	{
		write(1, " ", 1);
		n = s_nb[0] - '0';
		number = get_dizaine(n);
		write(1, get_dizaine(n), ft_len(number));
        ++s_nb;
		if (s_nb[1] == '0')
		{
			++s_nb;
		}
		else
		{
			write(1, " ",1);
			n = s_nb[0] - '0';
		    print_special_case(n);
		    ++s_nb;
		}
	}
}
