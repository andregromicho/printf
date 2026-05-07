/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:07:18 by abrandao          #+#    #+#             */
/*   Updated: 2026/05/07 15:07:35 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, format);
	if (format == 'x')
		count += ft_print_char("0123456789abcdef"[n % 16]);
	else
		count += ft_print_char("0123456789ABCDEF"[n % 16]);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_print_str("(nil)"));
	count = 0;
	count += ft_print_str("0x");
	count += ft_print_hex((unsigned long)ptr, 'x');
	return (count);
}

//unsigned long porque o ponteiro pode ser maior que um unsigned int,
// e 'x' porque o formato é sempre em minúsculo para ponteiros.
