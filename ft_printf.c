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

int	ft_check_type(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (type == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (type == 'p')
		count = ft_print_ptr(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		count = ft_print_nbr(va_arg(args, int));
	else if (type == 'u')
		count = ft_print_unbr(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), type);
	else if (type == '%')
		count = ft_print_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	int		check;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != 0)
			check = ft_check_type (str[i++ + 1], args);
		else if (str[i] != '%')
			check = ft_print_char(str[i]);
		else
			check = 0;
		if (check == -1)
			return (va_end(args), -1);
		count += check;
		i++;
	}
	va_end(args);
	return (count);
}

/* #include <stdio.h>

int	main()
{

	char *s = "Hello, World!";
	int d = 42;
	unsigned int u = 3000000000;
	void *p = s;
	unsigned int x = 305441741;
	unsigned int X = 305441741;
	void *ptr = NULL;
	char *null_str = NULL;

	ft_printf("String: %s\n", s);
	ft_printf("Decimal: %d\n", d);
	ft_printf("Unsigned: %u\n", u);
	ft_printf("Pointer: %p\n", p);
	ft_printf("Hex (lowercase): %x\n", x);
	ft_printf("Hex (uppercase): %X\n", X);
	ft_printf("Percent sign: %%\n");
	ft_printf("Null pointer: %p\n", ptr);
	printf("Expected output:%p\n", ptr);
	ft_printf("Null string: %s\n", null_str);
	printf("Expected output:%s\n", null_str);
	ft_printf("hello %");
	ft_printf("");
	return (0);
} */