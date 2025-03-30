/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnaire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeurer <marvin@student.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:52:40 by mmeurer           #+#    #+#             */
/*   Updated: 2025/02/23 21:53:37 by mmeurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char    *get_special_case(unsigned int n)
{
    return ((const char *[20]){
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    }[n]);
}

const char  *get_dizaine(unsigned int n)
{
    return ((const char *[]){
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety",

    }[n]);
}

const char  *get_other(unsigned int n)
{
    return ((const char *[]){
        "thousand",
        "million",
        "billion",
        "trillion",
        "quadrillion",
        "quintillion",
        "sextillion",
        "septillion",
        "octillion",
        "nonillion",
        "decillion",
        "undecillion",
    }[n]);
}
