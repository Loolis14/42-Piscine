/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:55:38 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/23 21:55:43 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h> // provides write
# include <stddef.h> // provides size_t

const char  *get_special_case(unsigned int n);
const char  *get_dizaine(unsigned int n);
const char  *get_other(unsigned int n);
int ft_len(const char *s);

void    print_under_99(const char *s_nb);
void	print_over_100(const char *s_nb);
void    print_every_three(const char *s_nb);

void    print_other(size_t n);
void    print_special_case(size_t n);
void    print_dizaine(const char *s_nb);

#endif //RUSH02_H
