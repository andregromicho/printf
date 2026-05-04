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

int check_type(char format, va_list args);
{
    int count;

    count = 0;
    if (format == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (format == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (format == 'p')
        count += ft_putptr(va_arg(args, void *));
    else if (format == 'd' || format == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if (format == 'u')
        count += ft_putunbr(va_arg(args, unsigned int));
    else if (format == 'x' || format == 'X')
        count += ft_puthex(va_arg(args, unsigned int), format);
    else if (format == '%')
        count += ft_putchar('%');
    return (count);
}

int ft_printf(const char *format, ...)
{
    int count;
    int i;
    va_list args;

    count = 0;
    i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += check_type(format[i], args);
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}
