/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:45:35 by abrandao          #+#    #+#             */
/*   Updated: 2026/05/04 15:45:46 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_type(char str, va_list args)
{
    int count;

    count = 0;
    if (str == 'c')
        count += ft_print_char(va_arg(args, int));
    else if (str == 's')
        count += ft_print_str(va_arg(args, char *));
    else if (str == 'p')
        count += ft_print_ptr(va_arg(args, void *));
    else if (str == 'd' || str == 'i')
        count += ft_print_nbr(va_arg(args, int));
    else if (str == 'u')
        count += ft_print_unbr(va_arg(args, unsigned int));
    else if (str == 'x' || str == 'X')
        count += ft_print_hex(va_arg(args, unsigned int), str);
    else if (str == '%')
        count += ft_putchar('%');
    return (count);
}

int ft_printf(const char *str, ...)
{
    int     count;
    int     i;
    va_list args;

    count = 0;
    i = 0;
    va_start(args, str);
    while  str[i])
    {
        if (str[i] == '%')
        {
            i++;
            count += check_type (str[i], args);
        }
        else
            count += ft_putchar (str[i]);
            i++;
    }
    va_end(args);
    return (count);
}
