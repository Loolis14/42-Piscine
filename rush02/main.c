/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:54:32 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/23 22:36:11 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stddef.h>

void    print_other(size_t n)
{
    const char	*number;

    number = get_other(n);
    write(1, number, ft_len(number));
    write(1, " ", 1);
}

void    print_special_case(size_t n)
{
    const char	*number;

    number = get_special_case(n);
	write(1, get_special_case(n), ft_len(number));
}

void    print_dizaine(const char *s_nb)
{
    const char  *number;
    size_t  x;
    size_t  n;

    x = (s_nb[0] - '0') * 10 + (s_nb[1] - '0');
	if (x == 0)
	{
		s_nb += 2;
	}
	else if (s_nb[0] == '0' && s_nb[1] != '0')
	{
		++s_nb;
		n = s_nb[0] - '0';
		print_special_case(n);
		++s_nb;
	}
	else if (x <= 19)
	{
		n = ((s_nb[0] - '0') * 10 + (s_nb[1] - '0'));
		print_special_case(n);
		s_nb += 2;
	}
	else
	{
		n = s_nb[0] - '0';
		number = get_dizaine(n);
		write(1, get_dizaine(n), ft_len(number));
        ++s_nb;
		if (s_nb[1] == '0')
			++s_nb;
		else
		{
			write(1, " ",1);
			n = s_nb[0] - '0';
		    print_special_case(n);
		    ++s_nb;
		}
	}
}

void    print_every_three(const char *s_nb)
{
	size_t  len_nb;
	size_t	n;

	len_nb = ft_len(s_nb);
	if (len_nb >= 3)
	{
		if (len_nb % 3 == 0)
		{
			print_over_100(s_nb);
            write(1, " ", 1);
            s_nb += 3;
            if (ft_len(s_nb) != 0)
            {
                n = (ft_len(s_nb) / 3 - 1);
                print_other(n);
            }
            print_every_three(s_nb);
		}
        else if (len_nb % 3 == 2)
		{
			print_dizaine(s_nb);
            write(1, " ", 1);
            s_nb += 2;
            if (ft_len(s_nb) != 0)
            {
                n = (ft_len(s_nb) / 3 - 1);
                print_other(n);
            }
            print_every_three(s_nb);
		}
        else
		{
			n = s_nb[0] - '0';
		    print_special_case(n);
		    ++s_nb;
            write(1, " ", 1);
            if (ft_len(s_nb) != 0)
            {
                n = (ft_len(s_nb) / 3 - 1);
                print_other(n);
            }
            print_every_three(s_nb);
		}
    }
	else if (len_nb < 3 && len_nb > 0)	
	{
		print_under_99(s_nb);
	}
}

int main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1,"Error\n" ,6);
		return (1);
	}
	i = 0;
	while(argv[1][i])
	{
		if(!(argv[1][i] >= '0' && argv[1][i] <= '9'))
		{
			write(1,"Error\n" ,6);
			return (1);
		}
	}
	print_every_three(argv[1]);
}
